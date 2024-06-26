#pragma once
#include <unordered_map>
#include <functional>
#include<SFML\Graphics.hpp>

class IWindow;

class InputManager
{
private:
	std::unordered_map<sf::Keyboard::Key, std::string> keyBindings;
	std::unordered_map<std::string, std::function<void()>> actionBindings;

public:
	virtual void ProcessInput(IWindow* _window);
	virtual void BindKey(sf::Keyboard::Key _keyToBind, std::string _actionName);
	virtual void BindAction(std::string _actionToBind, std::function<void()> _functionRef);
};