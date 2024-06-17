#pragma once

#include <gtest/gtest.h>
#include "ScoreManager.h"

class ScoreManagerTest : public ::testing::Test {
protected:
    ScoreManager scoreManager;
};

TEST_F(ScoreManagerTest, InitialScore) {
    ASSERT_EQ(scoreManager.GetScore(), 0);
}

TEST_F(ScoreManagerTest, AddScore) {
    scoreManager.AddScore(10);
    ASSERT_EQ(scoreManager.GetScore(), 10);

    scoreManager.AddScore(5);
    ASSERT_EQ(scoreManager.GetScore(), 15);
}

TEST_F(ScoreManagerTest, ResetScore) {
    scoreManager.AddScore(10);
    ASSERT_EQ(scoreManager.GetScore(), 10);

    scoreManager.ResetScore();
    ASSERT_EQ(scoreManager.GetScore(), 0);
}
