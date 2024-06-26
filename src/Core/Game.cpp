#include "Game.h"
#include "Snake.h"
#include "Food.h"
#include "Window.h"
#include <iostream>

Game::Game() : scoreDisplay(scoreManager)
{
    window = new Window(Constants::WINDOW_WIDTH, Constants::WINDOW_HEIGHT, "Snake Game");
    InitGame();
}

Game::~Game()
{
    ClearGame();
}

void Game::ResetGame()
{
    InitGame();
    scoreManager.ResetScore();
}

void Game::Run()
{
    std::srand(std::time(nullptr));

    while (window->GetRenderWindow().isOpen())
    {
        sf::Time _elapsedTime = clock.restart();
        deltaTime = _elapsedTime.asSeconds();

        inputManager.ProcessInput(window);
        Update(deltaTime);
        Render();
    }
}

void Game::InitGame()
{
    gameObjects["Snake_Actor"] = new Snake(*this, sf::Vector2f(10.f, 10.f), Constants::INITIAL_SNAKE_LENGTH, Constants::SNAKE_COLOR, false, MoveSettings(Constants::SNAKE_SPEED_INTERVAL), inputManager);
    gameObjects["Food_Actor"] = new Food(*this, sf::Vector2f(15.f, 10.f), Constants::FOOD_COLOR, false);
}

void Game::Update(const float _dt)
{
    UpdateGameObjects(_dt);
    CheckCollisions();
    scoreDisplay.UpdateScoreText();
}

void Game::UpdateGameObjects(const float _dt)
{
    for (auto& _currentGameObjects : gameObjects)
    {
        IUpdatable* _objectUpdatable = dynamic_cast<IUpdatable*>(_currentGameObjects.second);
        if (_objectUpdatable) _objectUpdatable->Update(_dt);
    }
}
void Game::CheckCollisionBetween(sf::Drawable* obj1, sf::Drawable* obj2)
{
    auto bounded1 = dynamic_cast<IBounded*>(obj1);
    auto bounded2 = dynamic_cast<IBounded*>(obj2);

    if (bounded1 && bounded2 && bounded1->GetBounds().intersects(bounded2->GetBounds())) {
        HandleCollision(bounded1, bounded2);
    }
}

void Game::HandleCollision(IBounded* bounded1, IBounded* bounded2)
{
    if (auto collidable1 = dynamic_cast<ICollidable*>(bounded1)) {
        collidable1->OnCollision(bounded2);
    }
    if (auto collidable2 = dynamic_cast<ICollidable*>(bounded2)) {
        collidable2->OnCollision(bounded1);
    }
}

void Game::CheckCollisions()
{
    for (auto it1 = gameObjects.begin(); it1 != gameObjects.end(); ++it1) {
        for (auto it2 = std::next(it1); it2 != gameObjects.end(); ++it2) {
            CheckCollisionBetween(it1->second, it2->second);
        }
    }
}

void Game::Render()
{
    window->GetRenderWindow().clear(sf::Color::Black);
    for (auto& _currentGameObjects : gameObjects)
    {
        window->GetRenderWindow().draw(*_currentGameObjects.second);
    }
    scoreDisplay.Draw(window->GetRenderWindow());
    window->GetRenderWindow().display();
}

void Game::ClearGame()
{
    for (auto& _currentGameObject : gameObjects)
    {
        delete _currentGameObject.second;
        _currentGameObject.second = nullptr;
    }
}
