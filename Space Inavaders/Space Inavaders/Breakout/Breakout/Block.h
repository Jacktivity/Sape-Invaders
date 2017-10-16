#pragma once
#include <SimpleMath.h>
#include "SpriteResources.h"
#include "CollisionBox.h"
class Block
{
public:
	Block(std::wstring textureID, DirectX::SimpleMath::Vector2 position);
	~Block();

private:
	std::wstring m_textureID;
public:
	DirectX::SimpleMath::Vector2 m_position;
	CollisionBox m_collisionBox;
	bool deleted;
protected:
	RECT m_rect;
public:
	void Render(std::shared_ptr<SpriteResources> spriteResources);
	virtual void Update() = 0;
	const CollisionBox& getAABB() const;
	void Delete();
	bool isDeleted();
	void setAABB(DirectX::SimpleMath::Vector2 position);
	DirectX::SimpleMath::Color spriteTint;
};

