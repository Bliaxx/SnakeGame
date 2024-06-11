#pragma once
#include <SFML\Graphics.hpp>

class MoveSettings
{
	float speed;

public:
	MoveSettings(const float _speed) : speed(_speed) {};
	~MoveSettings() = default;

public:
	float GetSpeed() { return speed; }
	void SetSpeed(const float _speed) { speed = _speed; }
};