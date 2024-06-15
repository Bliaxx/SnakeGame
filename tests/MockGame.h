#pragma once

#include "Game.h"
#include <gmock/gmock.h>

class MockGame : public Game {
public:
    MOCK_METHOD(sf::Vector2f, GetCellsResolution, (), (const, override));
};