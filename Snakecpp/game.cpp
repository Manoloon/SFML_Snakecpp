#include "game.h"

game::game():m_window("Snake Game", sf::Vector2u(800,600))
{
	RestartClock();
	srand(time(nullptr));
}

game::~game(){}

void game::HandleInput()
{
	// Input handling.
}

void game::Update()
{
	m_window.Update();
}

void game::Render()
{
	m_window.BeginDraw();
	m_window.EndDraw();
}

sf::Time game::GetTimeElapsed()
{
	return m_timeElapsed;
}

void game::RestartClock()
{
	m_timeElapsed = m_clock.restart();
}

window* game::GetWindow()
{
	return &m_window;
}
