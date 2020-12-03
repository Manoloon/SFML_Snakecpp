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
	
	window m_window;

	sf::Clock m_clock;
	sf::Time m_timeElapsed;

};

