#pragma once

#include <string>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <map>

#include "ResourceScreen.h"

using namespace std;

class MainMenuScreen {
public:
    bool process();

private:
    void printHeader();
    bool screenExists(const string& name);
    bool processCommand(const string& command);
    map<string, ResourceScreen> screens; // where all the ResourceScreens are stored
   
};
