#pragma once
#include "window.h"
class game
{
public:
	game();
	~game();
	void HandleInput();
	void Update();
	void Render();

	sf::Time GetTimeElapsed();
	void RestartClock();

	window* GetWindow();

private:
	void MoveSprite();

	window m_window;

	sf::Texture PowerTexture;
	sf::Sprite PowerSprite;
	sf::Vector2i m_Increment;

	sf::Clock m_clock;
	sf::Time m_timeElapsed;

};

