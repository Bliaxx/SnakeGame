#pragma once
#include <SFML\Graphics.hpp>

class TransformComponent
{
private:
    sf::Vector2f position;
    bool pixelCoordinatePosition = false;

public:
    TransformComponent(sf::Vector2f pos, const bool _enablePixelCoordinatePosition);

public:
    sf::Vector2f GetPosition() const;
    void SetPosition(sf::Vector2f _pos);

    inline bool IsPixelCoordinatePosition() const { return pixelCoordinatePosition; }
    inline void SetIsPixelCoordinatePosition(const bool _enable) { pixelCoordinatePosition = _enable; }
};
