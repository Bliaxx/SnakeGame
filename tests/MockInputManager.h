#pragma once

#include <gmock/gmock.h>
#include "InputManager.h"

class MockInputManager : public InputManager {
public:
    MOCK_METHOD(void, ProcessInput, (IWindow* window), (override));
    MOCK_METHOD(void, BindKey, (sf::Keyboard::Key keyToBind, std::string actionName), (override));
    MOCK_METHOD(void, BindAction, (std::string actionToBind, std::function<void()> functionRef), (override));
};
