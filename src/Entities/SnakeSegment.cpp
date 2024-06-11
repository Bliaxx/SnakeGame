#include "SnakeSegment.h"

SnakeSegment::SnakeSegment(Game& _gameRef, sf::Vector2f _pos, const sf::Color _segmentColor, bool _enablePixelCoordinate) : GameObject(_gameRef, _pos, _segmentColor, _enablePixelCoordinate)
{
    sprite.setSize(sf::Vector2f(Constants::CELL_SIZE, Constants::CELL_SIZE));
}

void SnakeSegment::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(sprite, states);
}
