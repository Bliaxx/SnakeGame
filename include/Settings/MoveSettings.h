#pragma once
#include <SFML\Graphics.hpp>

class MoveSettings
{
	float speedInterval;

public:
	MoveSettings(const float _speedInterval) : speedInterval(_speedInterval) {};
	~MoveSettings() = default;

public:
	float GetSpeedInterval() { return speedInterval; }
	void SetSpeedInterval(const float _speedInterval) { speedInterval = _speedInterval; }
};