#pragma once
#include "Block.h"
#include "DeviceResources.h"
class ToughBlock : public Block
{
public:
	ToughBlock(std::wstring textureID, DirectX::SimpleMath::Vector2 position);
	~ToughBlock();

public:
	virtual void Update();

private:
	bool hurt;
	RECT standard;
};

