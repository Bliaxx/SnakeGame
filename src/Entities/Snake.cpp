#include "Snake.h"
#include "Food.h"
#include <iostream>

Snake::Snake(Game& _gameRef, sf::Vector2f _initialPos, const int _initialLength, const sf::Color _snakeColor, const bool _enablePixelCoordinate, MoveSettings _moveSettings, InputManager& _inputManager) : 
	GameObject(_gameRef, _initialPos, _snakeColor, _enablePixelCoordinate), moveSettings(_moveSettings)
{
	InitDirectionsOffset();
	CreateSnakeBody(_initialPos, _initialLength, _snakeColor, _enablePixelCoordinate);
	SetupControls(_inputManager);
}

void Snake::ResetSnake()
{
	CreateSnakeBody(sf::Vector2f(10.f, 15.f), Constants::INITIAL_SNAKE_LENGTH, Constants::SNAKE_COLOR, false);
}

void Snake::SetupControls(InputManager& _inputManager)
{
	_inputManager.BindKey(sf::Keyboard::Up, "TurnUp");
	_inputManager.BindKey(sf::Keyboard::Down, "TurnDown");
	_inputManager.BindKey(sf::Keyboard::Left, "TurnLeft");
	_inputManager.BindKey(sf::Keyboard::Right, "TurnRight");

	_inputManager.BindAction("TurnUp", std::bind(&Snake::TurnUp, this));
	_inputManager.BindAction("TurnDown", std::bind(&Snake::TurnDown, this));
	_inputManager.BindAction("TurnLeft", std::bind(&Snake::TurnLeft, this));
	_inputManager.BindAction("TurnRight", std::bind(&Snake::TurnRight, this));
}

void Snake::InitDirectionsOffset()
{
	directionsOffset[Direction::NONE] = sf::Vector2f(0.f, 0.f);
	directionsOffset[Direction::UP] = sf::Vector2f(0.f, -1.f);
	directionsOffset[Direction::DOWN] = sf::Vector2f(0.f, 1.f);
	directionsOffset[Direction::LEFT] = sf::Vector2f(-1.f, 0.f);
	directionsOffset[Direction::RIGHT] = sf::Vector2f(1.f, 0.f);
}

void Snake::Move(const float _dt)
{
	std::vector<sf::Vector2f> _previousPosCell;
	for (size_t i = 0; i < snakeBody.size(); ++i)
	{
		_previousPosCell.push_back(snakeBody[i].GetPositionCellCoordinate());
	}

	AddPosition(directionsOffset[currentDirection]);

	for (size_t i = 1; i < snakeBody.size(); ++i) {

		snakeBody[i].SetPosition(_previousPosCell[i-1]);
	}

	HandleEdgeCrossing();
	CheckSelfCollision();
}

void Snake::CreateSnakeBody(sf::Vector2f _initialPosition, const int _bodyLength, const sf::Color _bodyColor, const bool _enablePixelCoordinateBodySnake)
{
	snakeBody.clear();
	for (size_t i = 0; i < _bodyLength; ++i)
	{
		snakeBody.push_back(SnakeSegment(gameRef, _initialPosition, _bodyColor, _enablePixelCoordinateBodySnake));
		_initialPosition.x -= 1;
	}
}

void Snake::TurnUp()
{
	if (currentDirection != Direction::DOWN) {
		currentDirection = Direction::UP;
	}
}

void Snake::TurnDown()
{
	if (currentDirection != Direction::UP) {
		currentDirection = Direction::DOWN;
	}
}

void Snake::TurnLeft()
{
	if (currentDirection != Direction::RIGHT) {
		currentDirection = Direction::LEFT;
	}
}

void Snake::TurnRight()
{
	if (currentDirection != Direction::LEFT) {
		currentDirection = Direction::RIGHT;
	}
}

void Snake::Update(const float _dt)
{
	static float elapsedTime = 0.f;
	elapsedTime += _dt;

	if (elapsedTime >= moveSettings.GetSpeedInterval()) {
		Move(_dt);
		elapsedTime = 0.f;
	}
}

void Snake::draw(sf::RenderTarget& _target, sf::RenderStates _states) const
{
	for (auto& _currentSnakeSegment : snakeBody)
	{
		_target.draw(_currentSnakeSegment, _states);
	}
}

sf::Vector2f Snake::GetPositionPixelCoordinate() const
{
	if (snakeBody.size() > 0)
		return snakeBody[0].GetPositionPixelCoordinate();
	return sf::Vector2f(0.f, 0.f);
}

sf::Vector2f Snake::GetPositionCellCoordinate() const
{
	if (snakeBody.size() > 0)
		return snakeBody[0].GetPositionCellCoordinate();
	return sf::Vector2f(0.f, 0.f);
}

void Snake::SetPosition(sf::Vector2f _pos)
{
	if (snakeBody.size() > 0)
		snakeBody[0].SetPosition(_pos);
}

void Snake::AddPosition(sf::Vector2f _addPos)
{
	if (snakeBody.size() > 0)
		snakeBody[0].AddPosition(_addPos);
}

void Snake::Grow()
{
	sf::Vector2f _newSnakeSegmentPos = transform.IsPixelCoordinatePosition() ? snakeBody.back().GetPositionPixelCoordinate() : snakeBody.back().GetPositionCellCoordinate();

	snakeBody.push_back(SnakeSegment(gameRef, _newSnakeSegmentPos, Constants::SNAKE_COLOR, false));
}

void Snake::HandleEdgeCrossing()
{
	sf::Vector2f _position = GetPositionCellCoordinate();

	if (_position.x < 0) {
		_position.x = Constants::WINDOW_WIDTH / Constants::CELL_SIZE - 1;
	}
	else if (_position.x >= Constants::WINDOW_WIDTH / Constants::CELL_SIZE) {
		_position.x = 0;
	}

	if (_position.y < 0) {
		_position.y = Constants::WINDOW_HEIGHT / Constants::CELL_SIZE - 1;
	}
	else if (_position.y >= Constants::WINDOW_HEIGHT / Constants::CELL_SIZE) {
		_position.y = 0;
	}

	SetPosition(_position);
}

void Snake::CheckSelfCollision()
{
	sf::FloatRect _headBounds = snakeBody[0].GetBounds();
	for (size_t i = 1; i < snakeBody.size(); ++i)
	{
		if (_headBounds.intersects(snakeBody[i].GetBounds()))
		{
			gameRef.ResetGame();
			ResetSnake();
		}
	}
}

void Snake::OnCollision(IBounded* _other)
{
	if (Food* _food = dynamic_cast<Food*>(_other))
	{
		_food->SpawnToRandomPosition();
		gameRef.GetScoreManager().AddScore(_food->GetScoreValue());
		Grow();
	}
}
