#pragma once

class IBounded;

class ICollidable
{
public:
	virtual ~ICollidable() = default;
	virtual void OnCollision(IBounded* _other) = 0;
};