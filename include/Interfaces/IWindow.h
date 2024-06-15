#pragma once
#include <SFML/Graphics.hpp>

class IWindow {
public:
    inline virtual sf::RenderWindow& GetRenderWindow() = 0;

    virtual ~IWindow() = default;
    virtual bool pollEvent(sf::Event& event) = 0;
    virtual void close() = 0;
};
