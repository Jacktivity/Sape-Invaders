#include "pch.h"
#include "Puck.h"


Puck::Puck(std::wstring textureID, std::shared_ptr<DX::DeviceResources> deviceResources, float gbheight, float gbwidth)
	: collisionBox{ DirectX::SimpleMath::Vector2(0,0), DirectX::SimpleMath::Vector2(32, 32) }
{
	m_position.x = gbwidth;
	m_textureID = textureID;
	m_puckHeight = 24;
	m_puckWidth = 164;
	float height = deviceResources->GetScreenViewport().Height;
	width = deviceResources->GetScreenViewport().Width;

	m_position.x = gbwidth / 2;
	m_position.y = gbheight - m_puckHeight;

	collisionBox.SetAABB(m_position);

	rect.left = 0;
	rect.top = 0;
	rect.right = 32;
	rect.bottom = 32;

	m_velocity = DirectX::SimpleMath::Vector2(500.0f, 0.0f);

	m_counter = 0;

	myPosx = m_position.x;
	myPosy = m_position.y;

}
Puck::~Puck()
{
}
void Puck::Update(double totalTime, double timeDelta, std::shared_ptr<GameController> controller)
{
	// calculate the new position
	float LX = controller->getLeftXNormalized();

	DirectX::SimpleMath::Vector2 velocity = m_velocity * LX;
	if (GetAsyncKeyState(VK_RIGHT))
	{
		velocity.x = 1000;
	}
	if (GetAsyncKeyState(VK_LEFT))
	{
		velocity.x = -1000;
	}
	DirectX::SimpleMath::Vector2 toMove = velocity * timeDelta;

	m_position = m_position + toMove;
	myPosx = m_position.x;
	myPosy = m_position.y;

	this->collisionBox.SetAABB(m_position);
	if (myPosx < -100)
	{
		m_position.x = width;
	}
	if (myPosx > width)
	{
		m_position.x = 0;
	}
	// check collision.
/*
	if (collisionBox.DoesIntersect(ball->getAABB()))
	{
		// calculate point of contact.
		DirectX::SimpleMath::Vector2 puckxcentre = this->collisionBox.getCentre();
		ball->ReverseVelocity(puckxcentre, m_puckWidth);
		m_counter = m_counter + 1;
	}
	*/
	
}
float Puck::returnHeight()
{
	return myPosy;
}
float Puck::returnWdith()
{
	return myPosx;
}
void Puck::Render(std::shared_ptr<SpriteResources> spriteResources)
{
	//Get the DirectX::SpriteBatch from the SpriteResources object
	spriteResources->GetSpriteBatch()->Draw(
		spriteResources->GetTexture(this->m_textureID).Get(),
		this->m_position,
		&rect,  //Need the raw C++ pointer
		DirectX::Colors::White.v,
		0,  //Angle of rotation in radians
		DirectX::SimpleMath::Vector2(0, 0), //Origin for the rotation
		1.0f, //Scale factor
		DirectX::SpriteEffects::SpriteEffects_None, //Reflections about the horizontal and verticle axes
		0.0f  //Layer depth; not required as we use DirectX::SpriteSortMode_Deferred
		);
}