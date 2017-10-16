#pragma once
#include <string>
#include "DeviceResources.h"
#include "GameController.h"
#include "SpriteResources.h"
#include "CollisionBox.h"
#include "SimpleMath.h"
#include "Disc.h"
class Puck
{
public:
	Puck(std::wstring textureID, std::shared_ptr<DX::DeviceResources> deviceResources,float height, float width);
	~Puck();

public:
	void Update(double totalTime, double timeDelta, std::shared_ptr<GameController> controller);
	float returnHeight();
	float returnWdith();
	void Render(std::shared_ptr<SpriteResources> spriteResources);

private:
	CollisionBox collisionBox;
	DirectX::SimpleMath::Vector2 m_position;
	std::wstring m_textureID;
	int m_puckHeight;
	int m_puckWidth;
	RECT rect;
	int m_counter;
	DirectX::SimpleMath::Vector2 m_velocity;
	float myPosx;
	float myPosy;
	float width;
};


