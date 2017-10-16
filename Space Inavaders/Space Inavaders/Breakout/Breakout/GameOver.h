#pragma once
#include "DeviceResources.h"
#include "SpriteResources.h"
#include "TextWriter.h"
#include <vector>
class GameOver
{
public:
	GameOver(std::shared_ptr<DX::DeviceResources> deviceResources);
	~GameOver();

	void Render(std::shared_ptr<SpriteResources> spriteResources);

private:
	std::shared_ptr<TextWriter> gameOverMessage;
};

