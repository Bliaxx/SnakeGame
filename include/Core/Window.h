#pragma once
#include "IWindow.h"
#include <SFML/Graphics.hpp>

class Window : public IWindow {
private:
    sf::RenderWindow& window;

public:
    Window(sf::RenderWindow& window) : window(window) {}

public:
    inline sf::RenderWindow& GetRenderWindow() override { return window; }

    virtual bool pollEvent(sf::Event& event) override {
        return window.pollEvent(event);
    }
    virtual void close() override {
        window.close();
    }
};
