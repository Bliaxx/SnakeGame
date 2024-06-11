#pragma once

class IUpdatable
{
public:
	virtual ~IUpdatable() = default;

public:
	virtual void Update(const float _dt) = 0;
};