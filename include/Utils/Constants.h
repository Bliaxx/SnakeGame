#pragma once
#include <SFML\Graphics.hpp>

class Constants
{
public:
    static const int WINDOW_WIDTH = 800;
    static const int WINDOW_HEIGHT = 600;

    static const int CELL_SIZE = 20;

    static const sf::Color SNAKE_COLOR;
    static const sf::Color FOOD_COLOR;

    static const int INITIAL_SNAKE_LENGTH = 3;

    static const std::string FONT_PATH;
};
