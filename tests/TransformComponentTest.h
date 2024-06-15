#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "TransformComponent.h"

class TransformComponentTest : public ::testing::Test {
protected:
    TransformComponent* transformComponent;

    virtual void SetUp() {
        transformComponent = new TransformComponent(sf::Vector2f(10.0f, 20.0f), false);
    }

    virtual void TearDown() {
        delete transformComponent;
    }
};

TEST_F(TransformComponentTest, InitialPosition) {
    sf::Vector2f expectedPosition(10.0f, 20.0f);
    ASSERT_EQ(transformComponent->GetPosition(), expectedPosition);
}

TEST_F(TransformComponentTest, SetPosition) {
    sf::Vector2f newPosition(30.0f, 40.0f);
    transformComponent->SetPosition(newPosition);
    ASSERT_EQ(transformComponent->GetPosition(), newPosition);
}

TEST_F(TransformComponentTest, PixelCoordinatePosition) {
    ASSERT_FALSE(transformComponent->IsPixelCoordinatePosition());
    transformComponent->SetIsPixelCoordinatePosition(true);
    ASSERT_TRUE(transformComponent->IsPixelCoordinatePosition());
}
