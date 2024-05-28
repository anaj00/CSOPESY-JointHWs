#pragma once
#include <string>
#include <ctime>
#include <iostream>
#include <sstream>

class ResourceScreen
{
public:
	ResourceScreen();
	ResourceScreen(std::string processName);
	void displayHeader();
	void displayScreen();

private:
	std::string processName;
	int currLine;
	int totalLines;
	std::string creationTimestamp;


};

