#pragma once
#include <SFML/Graphics.hpp>
#include "TransformComponent.h"
#include "Constants.h"
#include "Game.h"

template<typename SpriteType>
class GameObject : public sf::Drawable
{
protected:
    SpriteType sprite;
    TransformComponent transform;
    Game& gameRef;

public:
    GameObject(Game& _gameRef, sf::Vector2f pos, sf::Color color = sf::Color::White, bool _enablePixelCoordinate = false) : gameRef(_gameRef), transform(pos, _enablePixelCoordinate)
    {
        SetColor(color);
        SetPosition(pos);
    }

    virtual ~GameObject() = default;

protected:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

public:
    virtual void SetColor(const sf::Color _color);
    virtual void SetPosition(sf::Vector2f _pos);
    virtual void AddPosition(sf::Vector2f _addPos);
    virtual inline sf::Vector2f GetPositionPixelCoordinate() const { return transform.GetPosition(); }
    virtual inline sf::Vector2f GetPositionCellCoordinate() const {
        return transform.GetPosition() * 1.f / static_cast<float>(Constants::CELL_SIZE);
    }
};

template<>
void GameObject<sf::RectangleShape>::SetColor(const sf::Color _color);

template<>
void GameObject<sf::RectangleShape>::SetPosition(sf::Vector2f _pos);

template<>
void GameObject<sf::RectangleShape>::AddPosition(sf::Vector2f _addPos);


template<>
void GameObject<sf::CircleShape>::SetColor(const sf::Color _color);

template<>
void GameObject<sf::CircleShape>::SetPosition(sf::Vector2f _pos);

template<>
void GameObject<sf::CircleShape>::AddPosition(sf::Vector2f _addPos);