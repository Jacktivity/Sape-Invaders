#pragma once
#include <SimpleMath.h>
#include "Block.h"
#include "SpriteResources.h"
#include "CollisionBox.h"

#include <vector>
class Bullet
{
public:
	Bullet(std::wstring textureID, DirectX::SimpleMath::Vector2 position);
	~Bullet();
public:
	void Update(std::vector<std::shared_ptr<Block>> enemy, double totalTime, double timeDelta, DirectX::SimpleMath::Vector2 puckPosition);
	void Render(std::shared_ptr<SpriteResources> spriteResources);
	RECT m_rect;
private:
	std::wstring m_textureID;
public:
	const CollisionBox& getAABB() const;
	void Delete();
	DirectX::SimpleMath::Vector2 m_position;
	CollisionBox m_collisionBox;
	bool deleted;
};

