#pragma once
#include <SFML\Graphics.hpp>

class IBounded
{
public:
	virtual ~IBounded() = default;
	virtual sf::FloatRect GetBounds() const = 0;
};