#pragma once
#include <SFML/Graphics.hpp>
#include "ScoreManager.h"

class ScoreDisplay {
private:
    ScoreManager& scoreManager;
    sf::Font font;
    sf::Text scoreText;

public:
    ScoreDisplay(ScoreManager& _scoreManager);

public:
    inline std::string GetScoreText() const { return scoreText.getString(); }

    void UpdateScoreText();

    void Draw(sf::RenderWindow& window);
};
