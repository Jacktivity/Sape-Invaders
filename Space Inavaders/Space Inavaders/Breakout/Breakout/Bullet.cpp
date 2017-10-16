#include "pch.h"
#include "Bullet.h"
Bullet::Bullet(std::wstring textureID, DirectX::SimpleMath::Vector2 position)
	: m_collisionBox{ position + DirectX::SimpleMath::Vector2(0.0f, 0.0f), DirectX::SimpleMath::Vector2(8.0f, 16.0f) }
{
	RECT standard;
	standard.left = 0;
	standard.top = 0;
	standard.right = standard.left + 8;
	standard.bottom = 16;
	m_position = position;
	m_textureID = textureID;
	this->m_rect = standard;
	m_collisionBox.SetAABB(m_position);
	deleted = false;
}
Bullet::~Bullet()
{
}
void Bullet::Update(std::vector<std::shared_ptr<Block>> enemy, double totalTime, double timeDelta, DirectX::SimpleMath::Vector2 puckPosition)
{
	if (!deleted)
	{
		DirectX::SimpleMath::Vector2 velocity = DirectX::SimpleMath::Vector2(0.0, -32.0);
		DirectX::SimpleMath::Vector2 toMove = (m_position - velocity) * timeDelta;
		m_position.y += toMove.y;
		this->m_collisionBox.SetAABB(m_position);
		for (int i = 0; i < enemy.size(); i++)
		{
			if (enemy[i]->isDeleted() == false)
			{
				if (this->m_collisionBox.DoesIntersect(enemy[i]->getAABB()))
				{
					enemy[i]->Update();
					this->Delete();
					break;
				}
			}
		}
	}
}
void Bullet::Render(std::shared_ptr<SpriteResources> spriteResources)
{
	if (!deleted)
	{
			spriteResources->GetSpriteBatch()->Draw(
			spriteResources->GetTexture(this->m_textureID).Get(),
			this->m_position,
			&m_rect,  //Need the raw C++ pointer
			DirectX::Colors::White.v,
			0,  //Angle of rotation in radians
			DirectX::SimpleMath::Vector2(0, 0), //Origin for the rotation
			1.0f, //Scale factor
			DirectX::SpriteEffects::SpriteEffects_None, //Reflections about the horizontal and verticle axes
			0.0f  //Layer depth; not required as we use DirectX::SpriteSortMode_Deferred
		);
	}
}
const CollisionBox & Bullet::getAABB() const
{
	return this->m_collisionBox;
}
void Bullet::Delete()
{
	deleted = true;
}





