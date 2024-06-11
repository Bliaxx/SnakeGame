#include "Food.h"
#include "Constants.h"
#include "Utils.h"
#include <iostream>

Food::Food(Game& _gameRef, sf::Vector2f _pos, const sf::Color _colorFood, const bool _enablePixelCoordinate) : GameObject(_gameRef, _pos, _colorFood, _enablePixelCoordinate)
{
    sprite.setRadius(Constants::CELL_SIZE / 2);
}

void Food::SpawnToRandomPosition()
{
    const sf::Vector2f _rangeRandomWidth = sf::Vector2f(0.f, gameRef.GetCellsResolution().x-1);
    const sf::Vector2f _rangeRandomHeight = sf::Vector2f(0.f, gameRef.GetCellsResolution().y-1);
    const sf::Vector2u _spawnPosition = Utils::GetRandomPosition(_rangeRandomHeight, _rangeRandomHeight);
    SetPosition(static_cast<sf::Vector2f>(_spawnPosition));
}

void Food::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(sprite, states);
}
