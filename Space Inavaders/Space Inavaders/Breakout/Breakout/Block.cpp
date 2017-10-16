#include "pch.h"
#include "Block.h"
#include <iostream>

Block::Block(std::wstring textureID, DirectX::SimpleMath::Vector2 position)
	: m_collisionBox{ position + DirectX::SimpleMath::Vector2(0.0f, 0.0f), DirectX::SimpleMath::Vector2(32.0f, 32.0f) }
{
	m_position = position;
	m_collisionBox.SetAABB(m_position);
	m_textureID = textureID;
	deleted = false;
	spriteTint = DirectX::SimpleMath::Color(1, 1, 1, 1.0f);
}
Block::~Block()
{
}
void Block::Render(std::shared_ptr<SpriteResources> spriteResources)
{
	if (!deleted)
	{
		//Get the DirectX::SpriteBatch from the SpriteResources object
		spriteResources->GetSpriteBatch()->Draw(
			spriteResources->GetTexture(this->m_textureID).Get(),
			this->m_position,
			&m_rect,  //Need the raw C++ pointer
			this->spriteTint,
			0,  //Angle of rotation in radians
			DirectX::SimpleMath::Vector2(0, 0), //Origin for the rotation
			1.0f, //Scale factor
			DirectX::SpriteEffects::SpriteEffects_None, //Reflections about the horizontal and verticle axes
			0.0f  //Layer depth; not required as we use DirectX::SpriteSortMode_Deferred
		);
	}
}
const CollisionBox& Block::getAABB() const
{
	return this->m_collisionBox;
}
void Block::Delete()
{
	deleted = true;
}
bool Block::isDeleted()
{
	return deleted;
}
void Block::setAABB(DirectX::SimpleMath::Vector2 newPosition)
{
	m_collisionBox.SetAABB(newPosition);
}