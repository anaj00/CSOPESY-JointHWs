#pragma once

#include <string>
#include "MainMenuScreen.h"

using namespace std;
class ConsoleManager {
private:
    string* currentScreen;
    string* prevScreen;
    MainMenuScreen* mainMenuScreen;

public:
    // Constructor
    ConsoleManager(string* initialScreen = nullptr, MainMenuScreen* mainMenuScreen = nullptr);

    // Destructor
    ~ConsoleManager();

    // Getters
    const string* getCurrentScreen() const;
    const string* getPrevScreen() const;

    // Setters
    void setCurrentScreen(string* screen);
    void setPrevScreen(string* screen);

    // Interaction with MainMenuScreen
    void startConsole();
};
