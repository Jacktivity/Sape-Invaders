#pragma once
#include <string>
#include <SimpleMath.h>
#include <vector>
#include "States.h"
#include "Block.h"
#include "Bullet.h"
#include "StandardBlock.h"
#include "GameController.h"
#include "SpriteResources.h"
#include "DeviceResources.h"
#include "Puck.h"
class Breakout
{
public:
	Breakout(std::shared_ptr<DX::DeviceResources> deviceResources, std::shared_ptr<SpriteResources> spriteResources);
	~Breakout();

private:

	std::shared_ptr<Puck> m_puck;						// store the puck
	std::vector<std::shared_ptr<Block>> m_blocks;		// store the number of blocks
	std::vector<std::shared_ptr<Bullet>> m_bullet;		// store the number of blocks
	std::vector<std::shared_ptr<Block>> m_collidable;	// a list of blocks that we can collide with
	int m_level;										// store the current level
	int m_numInLevel;									// number of blocks in the level to destroy
	int m_numberDestroyed;								// number of blocks destroyed so far in the level
	int gameboardHeight;
	int gameboardWidth;
	int numOfVaders;
	int bullet;
	float puckX;
	float puckY;
	DirectX::SimpleMath::Vector2 puckPos;
	DirectX::SimpleMath::Vector2 value;
	
	

private:
	void BuildLevel(int level);

	//GameStates Update(double totalTime, double timeDelta, std::shared_ptr<GameController> controller);

public:
	GameStates Update(double totalTime, double timeDelta, std::shared_ptr<GameController> controller);
	void Render(std::shared_ptr<SpriteResources> spriteResources);

	DirectX::SimpleMath::Vector2 ReturnPuckPos();
	
public:
	std::shared_ptr<DX::DeviceResources> m_resources;

	float lastUpdate;
	float lastUpdateBull;
};

