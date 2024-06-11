#include "TransformComponent.h"

TransformComponent::TransformComponent(sf::Vector2f pos, const bool _enablePixelCoordinatePosition) : position(pos), pixelCoordinatePosition(_enablePixelCoordinatePosition) {}

sf::Vector2f TransformComponent::GetPosition() const
{
    return position;
}

void TransformComponent::SetPosition(sf::Vector2f _pos) {
    position = _pos;
}