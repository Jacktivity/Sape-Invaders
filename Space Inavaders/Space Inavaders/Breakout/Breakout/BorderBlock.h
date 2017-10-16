#pragma once
#include "Block.h"
class BorderBlock : public Block
{
public:
	BorderBlock(std::wstring textureID, DirectX::SimpleMath::Vector2 position);
	~BorderBlock();

public:
	virtual void Update();

};

