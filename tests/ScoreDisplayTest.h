#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <SFML/Graphics.hpp>
#include "ScoreDisplay.h"

class MockScoreManager : public ScoreManager {
public:
    MOCK_METHOD(int, GetScore, (), (const, override));
};

class ScoreDisplayTest : public ::testing::Test {
protected:
    MockScoreManager mockScoreManager;
    ScoreDisplay* scoreDisplay;
    sf::RenderWindow window;

    virtual void SetUp() {
        EXPECT_CALL(mockScoreManager, GetScore()).Times(1).WillOnce(testing::Return(0));
        scoreDisplay = new ScoreDisplay(mockScoreManager);
    }

    virtual void TearDown() {
        delete scoreDisplay;
    }
};

TEST_F(ScoreDisplayTest, InitialScoreText) {
    EXPECT_CALL(mockScoreManager, GetScore())
        .Times(1)
        .WillOnce(testing::Return(0));
    scoreDisplay->UpdateScoreText();
    ASSERT_EQ(scoreDisplay->GetScoreText(), "Score: 0");
}

TEST_F(ScoreDisplayTest, UpdateScoreText) {
    EXPECT_CALL(mockScoreManager, GetScore())
        .Times(1)
        .WillOnce(testing::Return(100));
    scoreDisplay->UpdateScoreText();
    ASSERT_EQ(scoreDisplay->GetScoreText(), "Score: 100");
}

TEST_F(ScoreDisplayTest, DrawScoreDisplay) {
    EXPECT_CALL(mockScoreManager, GetScore())
        .Times(1)
        .WillOnce(testing::Return(200));
    scoreDisplay->UpdateScoreText();
    scoreDisplay->Draw(window);
    ASSERT_EQ(scoreDisplay->GetScoreText(), "Score: 200");
}