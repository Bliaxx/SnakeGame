#pragma once
#include "InputManager.h"

class IInputReceiver
{
public:
	virtual ~IInputReceiver() = default;

public:
	virtual void SetupControls(InputManager& _inputManager) = 0;
};

