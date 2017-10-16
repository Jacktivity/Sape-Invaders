#include "pch.h"
#include "GameOver.h"


GameOver::GameOver(std::shared_ptr<DX::DeviceResources> deviceResources)
{
	float width = deviceResources->GetScreenViewport().Width / 2;
	float height = deviceResources->GetScreenViewport().Height / 2;
	DirectX::SimpleMath::Vector2 position(width, height);
	gameOverMessage = std::shared_ptr<TextWriter>(new TextWriter(L"Game Over!", position));
}


GameOver::~GameOver()
{
}

void GameOver::Render(std::shared_ptr<SpriteResources> resources)
{
	gameOverMessage->Render(resources);
}
