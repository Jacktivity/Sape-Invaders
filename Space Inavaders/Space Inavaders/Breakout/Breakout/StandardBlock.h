#pragma once
#include "Block.h"
#include "Bullet.h"
class StandardBlock : public Block
{
public:
	StandardBlock(std::wstring textureID, DirectX::SimpleMath::Vector2 position);
	~StandardBlock();

	


public:
	virtual void Update();
	
};

