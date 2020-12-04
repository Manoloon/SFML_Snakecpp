#include "game.h"


// inicializando la clase .
game::game():m_window("Snake Game", sf::Vector2u(800,600)),m_snake(m_world.GetBlockSize()),m_world(sf::Vector2u(800,600))
{
	m_clock.restart();
	srand(time(nullptr));
	m_timeElapsed = 0.0f;
}

game::~game(){}

void game::HandleInput()
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && m_snake.GetDirection() !=Direction::Down)
	{
		m_snake.SetDirection(Direction::Up);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && m_snake.GetDirection() !=Direction::Up)
	{
		m_snake.SetDirection(Direction::Down);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && m_snake.GetDirection() !=Direction::Right)
	{
		m_snake.SetDirection(Direction::Left);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && m_snake.GetDirection() !=Direction::Left)
	{
		m_snake.SetDirection(Direction::Right);
	}
}

void game::Update()
{
	m_window.Update();

	float timeStep = 1.0f / m_snake.GetSpeed();
	if (m_timeElapsed >= timeStep)
	{
		m_snake.Tick();
		m_world.Update(m_snake);
		m_timeElapsed -= timeStep;
		if(m_snake.HasLost())
		{
			m_snake.Reset();
		}
	}
}

void game::Render()
{
	m_window.BeginDraw();

	m_world.Render(*m_window.GetRenderWindow());
	m_snake.Render(*m_window.GetRenderWindow());

	m_window.EndDraw();
}

float game::GetTimeElapsed()
{
	return m_timeElapsed;
}

void game::RestartClock()
{
	m_timeElapsed += m_clock.restart().asSeconds();
}

window* game::GetWindow()
{
	return &m_window;
}
