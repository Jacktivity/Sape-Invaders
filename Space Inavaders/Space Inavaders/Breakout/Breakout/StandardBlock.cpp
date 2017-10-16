#include "pch.h"
#include "StandardBlock.h"


StandardBlock::StandardBlock(std::wstring textureID, DirectX::SimpleMath::Vector2 position) : Block(textureID, position)
{
	RECT standard;
	standard.left = 0;
	standard.top = 0;
	standard.right = standard.left + 32;
	standard.bottom = 32;

	this->m_rect = standard;
}
StandardBlock::~StandardBlock()
{
}
void StandardBlock::Update()
{
	this->Delete();
}
