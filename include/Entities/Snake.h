#pragma once
#include <vector>
#include "SnakeSegment.h"
#include "InputManager.h"
#include "IInputReceiver.h"
#include "IMovable.h"
#include "IUpdatable.h"
#include "MoveSettings.h"
#include "ICollidable.h"

class Snake : public GameObject<sf::RectangleShape>, public IInputReceiver, public IMovable, public IUpdatable, public IBounded, public ICollidable
{
	enum class Direction{NONE, UP, DOWN, LEFT, RIGHT};

private:
	std::vector<SnakeSegment> snakeBody;
	std::unordered_map<Direction, sf::Vector2f> directionsOffset;
	Direction currentDirection = Direction::RIGHT;
	MoveSettings moveSettings;
	bool allowGrow = false;

public:
	Snake(Game& _gameRef, sf::Vector2f _initialPos, const int _initialLength, const sf::Color _snakeColor, const bool _enablePixelCoordinate, MoveSettings _moveSettings, InputManager& _inputManager);
	~Snake() = default;

private:
	void ResetSnake();

	void SetupControls(InputManager& _inputManager) override;
	void InitDirectionsOffset();
	void CreateSnakeBody(sf::Vector2f _initialPosition, const int _bodyLength, const sf::Color _bodyColor, const bool _enablePixelCoordinateBodySnake);

	void Update(const float _dt) override;

	void draw(sf::RenderTarget& _target, sf::RenderStates _states) const override;

	void AddPosition(sf::Vector2f _addPos);

	void OnCollision(IBounded* _other) override;

public:
	inline int GetSnakeBodySize() const { return snakeBody.size(); }

	sf::Vector2f GetPositionPixelCoordinate() const override;
	sf::Vector2f GetPositionCellCoordinate() const override;

	sf::FloatRect GetBounds() const override { return snakeBody[0].GetBounds(); }

	void TurnUp();
	void TurnDown();
	void TurnLeft();
	void TurnRight();

	void Grow();

	void SetPosition(sf::Vector2f _pos);

	void Move(const float _dt) override;

	void HandleEdgeCrossing();

	void CheckSelfCollision();
};

