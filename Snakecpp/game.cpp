#include "game.h"

game::game():m_window("Movimiento sprite", sf::Vector2u(800,600))
{
	RestartClock();
	srand(time(NULL));

	// seteando las clases
	PowerTexture.loadFromFile("./Assets/Nes_Items.png");
	PowerSprite.setTexture(PowerTexture);
	m_Increment = sf::Vector2i(400, 400);
}

game::~game()
{
}

void game::HandleInput()
{
	// Input handling.
}

void game::Update()
{
	m_window.Update();
	MoveSprite();
}

void game::Render()
{
	m_window.BeginDraw();
	m_window.Draw(PowerSprite);
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

void game::MoveSprite()
{
	sf::Vector2u l_windSize = m_window.GetWindowSize();
	sf::Vector2u l_textureSize = PowerTexture.getSize();

	if((PowerSprite.getPosition().x > l_windSize.x - l_textureSize.x && m_Increment.x > 0) || (PowerSprite.getPosition().x < 0 && m_Increment.x < 0))
	{
		m_Increment.x = -m_Increment.x;
	}

	if((PowerSprite.getPosition().y > l_windSize.y - l_textureSize.y && m_Increment.y >0) || (PowerSprite.getPosition().y < 0 && m_Increment.y < 0))
	{
		m_Increment.y = -m_Increment.y;
	}
	float fTimeElapsed = m_timeElapsed.asSeconds();
	
	PowerSprite.setPosition(
		PowerSprite.getPosition().x + (m_Increment.x * fTimeElapsed),
		PowerSprite.getPosition().y + m_Increment.y * fTimeElapsed);
}
