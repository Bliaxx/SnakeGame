#include <gtest/gtest.h>
#include "GameObject.h"
#include <SFML/Graphics.hpp>

class MockGame : public Game {
public:
    MockGame() : Game() {}

    // Mocking the necessary methods used by GameObject
    MOCK_METHOD(sf::Vector2f, GetCellsResolution, (), (const, override));
    MOCK_METHOD(ScoreManager&, GetScoreManager, (), (override));
};

class GameObjectTest : public ::testing::Test {
protected:
    MockGame game;
    GameObject<sf::RectangleShape>* rectangleObject;
    GameObject<sf::CircleShape>* circleObject;

    virtual void SetUp() {
        rectangleObject = new GameObject<sf::RectangleShape>(game, sf::Vector2f(10.f, 10.f));
        circleObject = new GameObject<sf::CircleShape>(game, sf::Vector2f(20.f, 20.f));
    }

    virtual void TearDown() {
        delete rectangleObject;
        delete circleObject;
    }
};

TEST_F(GameObjectTest, RectangleSetColor) {
    sf::Color color = sf::Color::Red;
    rectangleObject->SetColor(color);
    ASSERT_EQ(rectangleObject->sprite.getFillColor(), color);
}

TEST_F(GameObjectTest, CircleSetColor) {
    sf::Color color = sf::Color::Blue;
    circleObject->SetColor(color);
    ASSERT_EQ(circleObject->sprite.getFillColor(), color);
}

TEST_F(GameObjectTest, RectangleSetPosition) {
    sf::Vector2f position(50.f, 50.f);
    rectangleObject->SetPosition(position);
    ASSERT_EQ(rectangleObject->GetPositionPixelCoordinate(), position);
    ASSERT_EQ(rectangleObject->sprite.getPosition(), position);
}

TEST_F(GameObjectTest, CircleSetPosition) {
    sf::Vector2f position(60.f, 60.f);
    circleObject->SetPosition(position);
    ASSERT_EQ(circleObject->GetPositionPixelCoordinate(), position);
    ASSERT_EQ(circleObject->sprite.getPosition(), position);
}

TEST_F(GameObjectTest, RectangleAddPosition) {
    sf::Vector2f addPosition(5.f, 5.f);
    sf::Vector2f newPosition = rectangleObject->GetPositionPixelCoordinate() + addPosition;
    rectangleObject->AddPosition(addPosition);
    ASSERT_EQ(rectangleObject->GetPositionPixelCoordinate(), newPosition);
    ASSERT_EQ(rectangleObject->sprite.getPosition(), newPosition);
}

TEST_F(GameObjectTest, CircleAddPosition) {
    sf::Vector2f addPosition(10.f, 10.f);
    sf::Vector2f newPosition = circleObject->GetPositionPixelCoordinate() + addPosition;
    circleObject->AddPosition(addPosition);
    ASSERT_EQ(circleObject->GetPositionPixelCoordinate(), newPosition);
    ASSERT_EQ(circleObject->sprite.getPosition(), newPosition);
}
