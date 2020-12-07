#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

struct SnakeSegment
{
	SnakeSegment(int x, int y) : position(x, y) {}
	sf::Vector2i position;
};
// alias del segmento de la vibora. 
using SnakeContainer = std::vector<SnakeSegment>;

// state machine! 
enum class Direction
{
None,
Up,
Down,
Left,
Right
};

class Snake
{
public:
	Snake(int l_blockSize);
	~Snake();

	// helper functions
	void SetDirection(Direction l_dir);
	Direction GetDirection();
	int GetSpeed();
	sf::Vector2i GetPosition();
	int GetLives();
	int GetScore();
	void IncreaseScore();
	bool HasLost();

	void Lose();
	void ToggleLost();
	void Extend(); // grow snake
	void Reset(); // reset starting position

	void Move();
	void Tick();
	void Cut(int l_segments); //cutting the snake
	void Render(sf::RenderWindow& l_window);

private:
	void CheckCollision();
	SnakeContainer m_snakeBody; // Snake segment vector
	int m_size; // Graphics size
	Direction m_dir;
	int m_speed;
	int m_lives;
	int m_score;
	bool bLost;
	sf::RectangleShape m_bodyRect;
};