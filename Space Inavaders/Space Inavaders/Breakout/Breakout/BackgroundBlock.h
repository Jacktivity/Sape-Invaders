#pragma once
#include "Block.h"
class BackgroundBlock : public Block
{
public:
	BackgroundBlock(std::wstring textureID, DirectX::SimpleMath::Vector2 position);
	~BackgroundBlock();

public:
	virtual void Update();
};

