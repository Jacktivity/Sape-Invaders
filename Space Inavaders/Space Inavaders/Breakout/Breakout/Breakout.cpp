#include "pch.h"
#include "Breakout.h"
#include "ToughBlock.h"
#include <fstream>
#include "BorderBlock.h"
#include "StandardBlock.h"
#include "ToughBlock.h"
#include "BackgroundBlock.h"

Breakout::Breakout(std::shared_ptr<DX::DeviceResources> deviceResources, std::shared_ptr<SpriteResources> spriteResources)
{
	m_level = 1;
	m_resources = deviceResources;
	this->BuildLevel(m_level);
	m_puck = std::shared_ptr<Puck>(new Puck(L"Assets/Spaceship.png", deviceResources, m_resources->GetScreenViewport().Height, (m_resources->GetScreenViewport().Width/2)));
	
	lastUpdate = 0.0f;
	lastUpdateBull = 0.0f;
	numOfVaders = 0;
	value.x = 63.0f;
	puckX = m_puck->returnWdith();
	puckY = m_puck->returnHeight();
	puckPos = DirectX::SimpleMath::Vector2(puckX, puckY);
	bullet = 0;
	
}
Breakout::~Breakout()
{
}
void Breakout::BuildLevel(int levelNumber)
{
	float screenWid = m_resources->GetScreenViewport().Width;
	float half = screenWid / 2;

	numOfVaders = std::floor(half / 63);

	int rowsStand = 5;
	int rowsTough = 3;
	DirectX::SimpleMath::Vector2 position = DirectX::SimpleMath::Vector2(0.0, 0.0);
	for (int i = 0; i < rowsTough; i++)
	{
		for (int j = 0; j < numOfVaders; j++)
		{
			std::shared_ptr<Block> b = std::make_shared<ToughBlock>(L"Assets/Invader2.png", position);
			m_blocks.push_back(b);
			position.x += 63;
		}
		position.x = 0.0f;
		position.y += 63;
	}
	for (int i = 0; i < rowsStand; i++)
	{
		for (int j= 0; j < numOfVaders; j++)
		{
			std::shared_ptr<Block> b = std::make_shared<StandardBlock>(L"Assets/Invader1.png", position);
			m_blocks.push_back(b);
			position.x += 63;
		}
		position.x = 0.0f;
		position.y += 63;
	}
}
GameStates Breakout::Update(double totalTime, double timeDelta, std::shared_ptr<GameController> controller)
{	
	DirectX::SimpleMath::Vector2 position = DirectX::SimpleMath::Vector2(0.0, 0.0);
	ReturnPuckPos();
	bool goDown;
	float timeDelay = 0;
	goDown = false;
	
	if (!m_bullet.empty())
	{
		for each (std::shared_ptr<Bullet> bull in m_bullet)
		{
			bull->Update(m_blocks, totalTime, timeDelta, puckPos);
		}
	}
	if (totalTime > lastUpdate + 0.5f)
	{
		if (m_blocks[0]->m_position.x <= 0.0f)
		{
			value.x = 63.0f;
			value.y = +64.0f;
			goDown = true;
		}
		else if (m_blocks[14]->m_position.x >= m_resources->GetScreenViewport().Width - 63)
		{
			value.x = -63.0f;
			value.y = +64.0f;;
			goDown = true;
		}
		for each (std::shared_ptr<Block> b in m_blocks)
		{
			b->m_position.x += value.x;
			if (goDown)
			{
				b->m_position.y += value.y;
			}
		}
		for each (std::shared_ptr<Block> b in m_blocks)
		{
			b->setAABB(b->m_position);
		}
		lastUpdate = totalTime;
	}
	for each (std::shared_ptr<Bullet> bull in m_bullet)
	{
		bull->m_position.y -= 32;
		if (bull->m_position.y < 0)
		{
			bull->Delete();
		}
	}
	for each (std::shared_ptr<Block> b in m_blocks)
	{
		//b->Update(m_bullet, totalTime, timeDelta, value);	
	}
	DirectX::SimpleMath::Vector2 bullposition = DirectX::SimpleMath::Vector2(puckX, puckY);
	if (controller->WasButtonReleaseDetected(XINPUT_GAMEPAD_A))
	{
			puckX = m_puck->returnWdith();
			puckY = m_puck->returnHeight();
			puckPos = DirectX::SimpleMath::Vector2(puckX, puckY - 33);
			std::shared_ptr<Bullet> bull = std::make_shared<Bullet>(L"Assets/SpaceBullet.png", puckPos);
			m_bullet.push_back(bull);
			bullet++;
	}
	GameStates state = GameStates::Playing_State;
	if (controller->WasButtonReleaseDetected(XINPUT_GAMEPAD_B) || GetAsyncKeyState(VK_ESCAPE))
	{
		state = GameStates::Playing_State;
	}
	if (state == GameStates::Playing_State)
	{
		m_puck->Update(totalTime, timeDelta, controller);
	}
	return GameStates::Playing_State;
}
void Breakout::Render(std::shared_ptr<SpriteResources> spriteResources)
{
	for (int i = 0; i < m_blocks.size(); i++)
	{
		m_blocks[i]->Render(spriteResources);
	}
	m_puck->Render(spriteResources);
	
	for (int j = 0; j < m_bullet.size(); j++)
	{
		m_bullet[j]->Render(spriteResources);
	}
}
DirectX::SimpleMath::Vector2 Breakout::ReturnPuckPos()
{
	return puckPos;
}