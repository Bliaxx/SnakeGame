#pragma once

#include <gtest/gtest.h>
#include "SnakeSegment.h"
#include "MockGame.h"

class SnakeSegmentTest : public ::testing::Test {
protected:
    MockGame mockGame;
    SnakeSegment* snakeSegment;

    virtual void SetUp() {
        snakeSegment = new SnakeSegment(mockGame, sf::Vector2f(10.f, 10.f), sf::Color::Green, false);
    }

    virtual void TearDown() {
        delete snakeSegment;
    }
};

TEST_F(SnakeSegmentTest, InitialPosition) {
    ASSERT_EQ(snakeSegment->GetPositionCellCoordinate(), sf::Vector2f(10.f, 10.f));
}

TEST_F(SnakeSegmentTest, GetBounds) {
    sf::FloatRect bounds = snakeSegment->GetBounds();
    ASSERT_FLOAT_EQ(bounds.left, 10.f * Constants::CELL_SIZE);
    ASSERT_FLOAT_EQ(bounds.top, 10.f * Constants::CELL_SIZE);
    ASSERT_FLOAT_EQ(bounds.width, Constants::CELL_SIZE);
    ASSERT_FLOAT_EQ(bounds.height, Constants::CELL_SIZE);
}

TEST_F(SnakeSegmentTest, Draw) {
    sf::RenderWindow window(sf::VideoMode(Constants::WINDOW_WIDTH, Constants::WINDOW_HEIGHT), "Test Window");
    window.clear(sf::Color::Black);
    snakeSegment->draw(window, sf::RenderStates::Default);
    SUCCEED();
}
