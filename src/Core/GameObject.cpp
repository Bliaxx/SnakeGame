#include "GameObject.h"

template<>
void GameObject<sf::RectangleShape>::SetColor(const sf::Color _color)
{
    sprite.setFillColor(_color);
}

template<>
void GameObject<sf::RectangleShape>::SetPosition(sf::Vector2f _pos)
{
    transform.SetPosition(transform.IsPixelCoordinatePosition() ? _pos : static_cast<float>(Constants::CELL_SIZE) * _pos);
    sprite.setPosition(transform.IsPixelCoordinatePosition() ? _pos : static_cast<float>(Constants::CELL_SIZE) * _pos);
}

template<>
void GameObject<sf::RectangleShape>::AddPosition(sf::Vector2f _addPos)
{
    SetPosition(transform.IsPixelCoordinatePosition() ? GetPositionPixelCoordinate() + _addPos : GetPositionCellCoordinate() + _addPos);
}

template<>
void GameObject<sf::CircleShape>::SetColor(const sf::Color _color)
{
    sprite.setFillColor(_color);
}

template<>
void GameObject<sf::CircleShape>::SetPosition(sf::Vector2f _pos)
{
    transform.SetPosition(transform.IsPixelCoordinatePosition() ? _pos : static_cast<float>(Constants::CELL_SIZE) * _pos);
    sprite.setPosition(transform.IsPixelCoordinatePosition() ? _pos : static_cast<float>(Constants::CELL_SIZE) * _pos);
}

template<>
void GameObject<sf::CircleShape>::AddPosition(sf::Vector2f _addPos)
{
    SetPosition(transform.IsPixelCoordinatePosition() ? GetPositionPixelCoordinate() + _addPos : GetPositionCellCoordinate() + _addPos);
}