/*#pragma once
#include <SimpleMath.h>
#include <string>
#include "DeviceResources.h"
#include "SpriteResources.h"
#include "CollisionBox.h"
#include <vector>
#include "Block.h"
#include "States.h"
class Disc
{
public:
	Disc(std::wstring textureID, std::shared_ptr<DX::DeviceResources> deviceResources, int puckHeight, int gbwidth, int gbheight);
	~Disc();

private:
	std::wstring textureID;
	DirectX::SimpleMath::Vector2 m_ballPosition;
	DirectX::SimpleMath::Vector2 m_ballVelocity;
	float width;
	float height;
	CollisionBox collisionBox;
	DirectX::SimpleMath::Vector2 discSize;

	int gameboardWidth;
	int gameboardHeight;

	float maximumXVelocity;
public:
	GameStates Update(double totalTime, double timeDelta);
	void Render(std::shared_ptr<SpriteResources> spriteResources);
	void ReverseVelocity(DirectX::SimpleMath::Vector2 puckCentre, int puckWidth);
	const CollisionBox& getAABB() const;
};*/

