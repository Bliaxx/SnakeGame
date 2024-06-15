#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Snake.h"
#include "MockGame.h"
#include "MockInputManager.h"
#include "Constants.h"

class SnakeTest : public ::testing::Test {
protected:
    MockGame mockGame;
    MockInputManager mockInputManager;
    Snake* snake;

    virtual void SetUp() {
        MoveSettings moveSettings(1.0f);
        EXPECT_CALL(mockInputManager, BindKey(sf::Keyboard::Up, "TurnUp")).Times(1);
        EXPECT_CALL(mockInputManager, BindKey(sf::Keyboard::Down, "TurnDown")).Times(1);
        EXPECT_CALL(mockInputManager, BindKey(sf::Keyboard::Left, "TurnLeft")).Times(1);
        EXPECT_CALL(mockInputManager, BindKey(sf::Keyboard::Right, "TurnRight")).Times(1);

        EXPECT_CALL(mockInputManager, BindAction("TurnUp", testing::_)).Times(1);
        EXPECT_CALL(mockInputManager, BindAction("TurnDown", testing::_)).Times(1);
        EXPECT_CALL(mockInputManager, BindAction("TurnLeft", testing::_)).Times(1);
        EXPECT_CALL(mockInputManager, BindAction("TurnRight", testing::_)).Times(1);

        snake = new Snake(mockGame, sf::Vector2f(10.f, 10.f), Constants::INITIAL_SNAKE_LENGTH, sf::Color::Green, false, moveSettings, mockInputManager);
    }

    virtual void TearDown() {
        delete snake;
    }
};

TEST_F(SnakeTest, InitialPosition) {
    ASSERT_EQ(snake->GetPositionCellCoordinate(), sf::Vector2f(10.f, 10.f));
}

TEST_F(SnakeTest, TurnUp) {
    snake->TurnUp();
    ASSERT_NO_THROW(snake->Move(0.1f));
}

TEST_F(SnakeTest, TurnDown) {
    snake->TurnDown();
    ASSERT_NO_THROW(snake->Move(0.1f));
}

TEST_F(SnakeTest, TurnLeft) {
    snake->TurnLeft();
    ASSERT_NO_THROW(snake->Move(0.1f));
}

TEST_F(SnakeTest, TurnRight) {
    snake->TurnRight();
    ASSERT_NO_THROW(snake->Move(0.1f));
}

TEST_F(SnakeTest, Grow) {
    size_t initialSize = snake->GetSnakeBodySize();
    snake->Grow();
    ASSERT_EQ(snake->GetSnakeBodySize(), initialSize + 1);
}

TEST_F(SnakeTest, Move) {
    sf::Vector2f initialPosition = snake->GetPositionCellCoordinate();
    snake->Move(0.1f);
    sf::Vector2f newPosition = snake->GetPositionCellCoordinate();
    ASSERT_NE(initialPosition, newPosition);
}

TEST_F(SnakeTest, HandleEdgeCrossing) {
    snake->SetPosition(sf::Vector2f(-1.f, 10.f));
    snake->HandleEdgeCrossing();
    ASSERT_EQ(snake->GetPositionCellCoordinate().x, Constants::WINDOW_WIDTH / Constants::CELL_SIZE - 1);

    snake->SetPosition(sf::Vector2f(Constants::WINDOW_WIDTH / Constants::CELL_SIZE, 10.f));
    snake->HandleEdgeCrossing();
    ASSERT_EQ(snake->GetPositionCellCoordinate().x, 0.f);
}

TEST_F(SnakeTest, CheckSelfCollision) {
    snake->Grow();
    snake->Grow();
    snake->SetPosition(snake->GetPositionCellCoordinate());
    ASSERT_NO_THROW(snake->CheckSelfCollision());
}
