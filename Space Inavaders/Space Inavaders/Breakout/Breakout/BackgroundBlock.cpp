#include "pch.h"
#include "BackgroundBlock.h"


BackgroundBlock::BackgroundBlock(std::wstring textureID, DirectX::SimpleMath::Vector2 position) : Block(textureID, position)
{
	RECT border;

	border.left = 0;
	border.top = 0;
	border.right = border.left + 32;
	border.bottom = 32;

	this->m_rect = border;
}


BackgroundBlock::~BackgroundBlock()
{
}

void BackgroundBlock::Update()
{

}