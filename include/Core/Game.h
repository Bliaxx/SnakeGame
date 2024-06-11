#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "InputManager.h"
#include "ScoreManager.h"
#include "ScoreDisplay.h"

class Game {
private:
    sf::RenderWindow window;
    InputManager inputManager;
    ScoreManager scoreManager;
    ScoreDisplay scoreDisplay;
    sf::Clock clock;
    float deltaTime = 0.0f;
    std::unordered_map<std::string, sf::Drawable*> gameObjects;

public:
    Game();
    ~Game();

private:
    void InitGame();
    void Update(const float _dt);
    void UpdateGameObjects(const float _dt);
    void CheckCollisions();
    void Render();
    void ClearGame();

public:
    void ResetGame();
    void Run();

    sf::Vector2f GetCellsResolution() const { return static_cast<sf::Vector2f>(window.getSize()) * 1.0f / static_cast<float>(Constants::CELL_SIZE); }
    inline ScoreManager& GetScoreManager() { return scoreManager; }
};
