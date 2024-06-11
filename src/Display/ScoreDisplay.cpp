#include "ScoreDisplay.h"
#include "Constants.h"
#include <iostream>

ScoreDisplay::ScoreDisplay(ScoreManager& _scoreManager) : scoreManager(_scoreManager)
{
    if (!font.loadFromFile(Constants::FONT_PATH)) {
        std::cerr << "Error: Could not load font file!" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);
    UpdateScoreText();
}

void ScoreDisplay::UpdateScoreText()
{
    scoreText.setString("Score: " + std::to_string(scoreManager.GetScore()));
}

void ScoreDisplay::Draw(sf::RenderWindow& window)
{
    window.draw(scoreText);
}
