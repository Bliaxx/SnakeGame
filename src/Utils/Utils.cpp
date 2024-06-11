#include "Utils.h"

sf::Vector2u Utils::GetRandomPosition(const sf::Vector2f _widthRange, const sf::Vector2f _heightRange)
{
	const unsigned int _randWidth = _widthRange.x + (std::rand() % static_cast<unsigned int>((_widthRange.y - _widthRange.x + 1)));
	const unsigned int _randHeight = _heightRange.x + (std::rand() % static_cast<unsigned int>((_heightRange.y - _heightRange.x + 1)));
	return sf::Vector2u(_randWidth, _randHeight);
}
