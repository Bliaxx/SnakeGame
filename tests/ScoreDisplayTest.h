#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <SFML/Graphics.hpp>
#include "ScoreDisplay.h"
#include "ScoreManager.h"

class MockScoreManager : public ScoreManager {
public:
    MOCK_METHOD(int, GetScore, (), (const));
};

class ScoreDisplayTest : public ::testing::Test {
protected:
    MockScoreManager mockScoreManager;
    ScoreDisplay* scoreDisplay;
    sf::RenderWindow window;

    virtual void SetUp() {
        scoreDisplay = new ScoreDisplay(mockScoreManager);
    }

    virtual void TearDown() {
        delete scoreDisplay;
    }
};

TEST_F(ScoreDisplayTest, InitialScoreText) {
    EXPECT_CALL(mockScoreManager, GetScore()).WillOnce(testing::Return(0));
    scoreDisplay->UpdateScoreText();
    // Pas de m�thode directe pour v�rifier le texte, on v�rifie donc si l'appel fonctionne sans erreur.
}

TEST_F(ScoreDisplayTest, UpdateScoreText) {
    EXPECT_CALL(mockScoreManager, GetScore()).WillOnce(testing::Return(100));
    scoreDisplay->UpdateScoreText();
    // Ici aussi, on s'assure que l'appel fonctionne correctement.
}

TEST_F(ScoreDisplayTest, DrawScoreDisplay) {
    EXPECT_CALL(mockScoreManager, GetScore()).WillOnce(testing::Return(200));
    scoreDisplay->UpdateScoreText();
    // Pour v�rifier le rendu, nous nous assurons que Draw peut �tre appel� sans erreur.
    scoreDisplay->Draw(window);
}

