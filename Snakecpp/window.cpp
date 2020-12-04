#include "window.h"

window::window()
{
	Setup("Window", sf::Vector2u(640, 480));
}

window::window(const std::string& l_title, const sf::Vector2u& l_size)
{
	Setup(l_title, l_size);
}

window::~window()
{
	Destroy();
}

void window::Setup(const std::string& l_title, const sf::Vector2u& l_size)
{
	m_windowTitle = l_title;
	m_windowSize = l_size;
	m_isFullscreen = false;
	m_isDone = false;
	m_window.setFramerateLimit(60);
	Create();
}

void window::BeginDraw()
{
	m_window.clear(sf::Color::Black);
}

void window::EndDraw()
{
	m_window.display();
}

void window::Update()
{
	sf::Event event;

	while(m_window.pollEvent(event))
	{
		if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F5)
		{
			ToggleFullscreen();
		}
		if (event.type == sf::Event::Closed)
		{
			m_window.close(); 
		}
	}
}

bool window::IsDone()
{
	return m_isDone;
}

bool window::IsFullscreen()
{
	return m_isFullscreen;
}

sf::Vector2u window::GetWindowSize()
{
	return m_windowSize;
}

sf::RenderWindow* window::GetRenderWindow()
{
	return &m_window;
}

void window::ToggleFullscreen()
{
	m_isFullscreen = !m_isFullscreen;
	Destroy();
	Create();
}

void window::Draw(sf::Drawable& l_Drawable)
{
	m_window.draw(l_Drawable);
}



void window::Destroy()
{
	m_window.close();
}

void window::Create()
{
	auto style = (m_isFullscreen ? sf::Style::Fullscreen 
		: sf::Style::Default);
	m_window.create({ m_windowSize.x, m_windowSize.y, 32 }, 
		m_windowTitle, style);
}
