#pragma once
#include <string>
#include <ctime>
#include <iostream>
#include <sstream>

using namespace std;
class ResourceScreen
{
public:
	ResourceScreen();
	ResourceScreen(string processName);
	void displayHeader();
	void displayScreen();

private:
	string processName;
	int currLine;
	int totalLines;
	string creationTimestamp;
};
