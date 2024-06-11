#pragma once
#include "GameObject.h"
#include <SFML\Graphics.hpp>
#include "Constants.h"
#include "IBounded.h"

class SnakeSegment : public GameObject<sf::RectangleShape>, public IBounded
{
public:
    SnakeSegment(Game& _gameRef, sf::Vector2f _pos, const sf::Color _segmentColor, bool _enablePixelCoordinate = false);

public:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    sf::FloatRect GetBounds() const override { return sprite.getGlobalBounds(); }
};
