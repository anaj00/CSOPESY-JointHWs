#pragma once
#include <iostream>
#include <string>
#include <cstdlib> // for cls

#define RESET "\033[0m"
#define RED "\033[31m"
#define YELLOW "\033[33m"

class MainMenuScreen
{
public:
	void printHeader();
	void processCommand(const std::string& command);
	bool process();
};

