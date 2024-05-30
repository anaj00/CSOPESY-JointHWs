#pragma once

#include <string>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <map>

#include "ResourceScreen.h"


class MainMenuScreen {
public:
    bool process();

private:
    void printHeader();
    bool screenExists(const std::string& name);
    bool processCommand(const std::string& command);
    std::map<std::string, ResourceScreen> screens; // where all the ResourceScreens are stored
   
};
