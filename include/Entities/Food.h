#pragma once
#include "GameObject.h"
#include "IBounded.h"
#include "IScorable.h"

class Food : public GameObject<sf::CircleShape>, public IBounded, public IScorable
{
public:
    Food(Game& _gameRef, sf::Vector2f _pos, const sf::Color _colorFood, const bool _enablePixelCoordinate);

private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:
    void SpawnToRandomPosition();
    sf::FloatRect GetBounds() const override { return sprite.getGlobalBounds(); }
    int GetScoreValue() const { return 10; }
};
