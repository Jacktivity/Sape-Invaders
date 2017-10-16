#include "pch.h"
#include "ToughBlock.h"


ToughBlock::ToughBlock(std::wstring textureID, DirectX::SimpleMath::Vector2 position) : Block(textureID, position)
{
	hurt = false; 
	RECT tough;
	tough.left = 0;
	tough.top = 0;
	tough.right = tough.left + 32;
	tough.bottom = 32;
	this->m_rect = tough;
	spriteTint = DirectX::SimpleMath::Color(0.5, 0.5, 0.5, 1.0f);
}
ToughBlock::~ToughBlock()
{
}
void ToughBlock::Update()
{
	if(hurt)
	{
		this->Delete();
	}
	hurt = true;
	spriteTint = DirectX::SimpleMath::Color(1, 0, 0, 1.0f);
}