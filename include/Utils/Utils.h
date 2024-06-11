#pragma once
#include <SFML\Graphics.hpp>

class Utils
{
public:
	static sf::Vector2u GetRandomPosition(const sf::Vector2f _widthRange, const sf::Vector2f _heightRange);
};

