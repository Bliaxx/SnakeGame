#include "InputManager.h"
#include "IWindow.h"

void InputManager::ProcessInput(IWindow* _window)
{
	if (!_window)
		throw std::runtime_error("ProcessInput Function : Window param is nullptr !");

	sf::Event _event;
	while (_window->pollEvent(_event))
	{
		if (_event.type == sf::Event::Closed)
		{
			_window->close();
		}
		else if (_event.type == sf::Event::KeyPressed)
		{
			auto _keyBindingsIt = keyBindings.find(_event.key.code);
			if (_keyBindingsIt != keyBindings.end())
			{
				std::string _actionName = _keyBindingsIt->second;
				auto _actionBindingsIt = actionBindings.find(_actionName);
				if (_actionBindingsIt != actionBindings.end())
				{
					_actionBindingsIt->second();
				}
			}
		}
	}
}

void InputManager::BindKey(sf::Keyboard::Key _keyToBind, std::string _actionName)
{
	keyBindings[_keyToBind] = _actionName;
}

void InputManager::BindAction(std::string _actionToBind, std::function<void()> _functionRef)
{
	if (!_functionRef)
		throw std::runtime_error("BindAction Function : functionRef param is null");

	actionBindings[_actionToBind] = _functionRef;
}
