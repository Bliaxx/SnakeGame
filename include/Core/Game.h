#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "InputManager.h"
#include "ScoreManager.h"
#include "ScoreDisplay.h"
#include "IWindow.h"

class Game {
private:
    IWindow* window;
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
    void Update(const float _dt);
    void UpdateGameObjects(const float _dt);
    void CheckCollisions();
    void Render();
    void ClearGame();

public:
    inline const std::unordered_map<std::string, sf::Drawable*> GetGameObjects() const { return gameObjects; }

    void InitGame();
    void ResetGame();
    void Run();

    virtual sf::Vector2f GetCellsResolution() const { return static_cast<sf::Vector2f>(window->GetRenderWindow().getSize()) * 1.0f / static_cast<float>(Constants::CELL_SIZE); }
    inline ScoreManager& GetScoreManager() { return scoreManager; }
};
