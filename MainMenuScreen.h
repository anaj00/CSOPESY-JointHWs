#pragma once

#include <string>

class MainMenuScreen {
public:
    void printHeader();
    void processCommand(const std::string& command);
    bool process();
};
