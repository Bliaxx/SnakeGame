#pragma once

class IMovable
{
public:
	virtual ~IMovable() = default;

public:
	virtual void Move(const float _dt) = 0;
};