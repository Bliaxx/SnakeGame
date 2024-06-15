#pragma once

#include "Window.h"
#include <gmock/gmock.h>

class MockWindow : public Window {
private:
    sf::RenderWindow mockRenderWindow;

public:
    MockWindow() : Window(Constants::WINDOW_WIDTH, Constants::WINDOW_HEIGHT, "Snake Game") {}

public:
    MOCK_METHOD(bool, pollEvent, (sf::Event& event), (override));
    MOCK_METHOD(void, close, (), (override));
    MOCK_METHOD(sf::RenderWindow&, GetRenderWindow, (), (override));
};