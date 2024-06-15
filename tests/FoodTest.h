#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Food.h"
#include "Game.h"
#include <iostream>

// Mock class for Game
class MockGame : public Game {
public:
    MOCK_METHOD(sf::Vector2f, GetCellsResolution, (), (const, override));
};

// Classe de test pour Food
class FoodTest : public ::testing::Test {
protected:
    MockGame mockGame;
    Food* food;

    virtual void SetUp() {
        EXPECT_CALL(mockGame, GetCellsResolution()).WillRepeatedly(testing::Return(sf::Vector2f(10.f, 10.f)));
        food = new Food(mockGame, sf::Vector2f(15.0f, 10.0f), sf::Color::Red, false);
    }

    virtual void TearDown() {
        delete food;
    }
};

TEST_F(FoodTest, InitialPosition) {
    sf::Vector2f expectedPosition(15.0f, 10.0f);
    ASSERT_EQ(food->GetPositionCellCoordinate(), expectedPosition);
}

TEST_F(FoodTest, SpawnToRandomPosition) {
    EXPECT_CALL(mockGame, GetCellsResolution()).WillRepeatedly(testing::Return(sf::Vector2f(10.f, 10.f)));

    food->SpawnToRandomPosition();
    auto bounds = food->GetBounds();
    ASSERT_TRUE(bounds.left >= 0 && bounds.left < 10 * Constants::CELL_SIZE);
    ASSERT_TRUE(bounds.top >= 0 && bounds.top < 10 * Constants::CELL_SIZE);
}

TEST_F(FoodTest, GetScoreValue) {
    ASSERT_EQ(food->GetScoreValue(), 10);
}
