#pragma once
#include "Command.h"
#include <memory>

class InputHandler {
public:
	ICommand* HandleInput();

	void AssignMoveLeftCommand2PressA();
	void AssignMoveRightCommand2PressD();
private:
	std::unique_ptr<ICommand> pressKeyD_;
	std::unique_ptr<ICommand> pressKeyA_;
};

