#pragma once
#include <unordered_map>
#include <functional>
#include<SFML\Graphics.hpp>

class InputManager
{
private:
	std::unordered_map<sf::Keyboard::Key, std::string> keyBindings;
	std::unordered_map<std::string, std::function<void()>> actionBindings;

public:
	void ProcessInput(sf::RenderWindow& _window);
	void BindKey(sf::Keyboard::Key _keyToBind, std::string _actionName);
	void BindAction(std::string _actionToBind, std::function<void()> _functionRef);
};