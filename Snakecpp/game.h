#pragma once
#include "window.h"
#include "snake.h"
#include "World.h"

class game
{
public:
	game();
	~game();
	void HandleInput();
	void Update();
	void Render();

	float GetTimeElapsed();
	void RestartClock();

	window* GetWindow();

private:
	
	window m_window;

	sf::Clock m_clock;
	float m_timeElapsed;

	World m_world;
	Snake m_snake;

	//inputs
	// definir variables con multiples inputs.
};

