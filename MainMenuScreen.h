#pragma once

#include <string>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <sstream>

class MainMenuScreen {
public:
    void printHeader();
    void processCommand(const std::string& command);
    bool process();
};
