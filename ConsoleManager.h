#pragma once

#include <string>
#include "MainMenuScreen.h"

class ConsoleManager {
private:
    std::string* currentScreen;
    std::string* prevScreen;
    MainMenuScreen* mainMenuScreen;

public:
    // Constructor
    ConsoleManager(std::string* initialScreen = nullptr, MainMenuScreen* mainMenuScreen = nullptr);

    // Destructor
    ~ConsoleManager();

    // Getters
    const std::string* getCurrentScreen() const;
    const std::string* getPrevScreen() const;

    // Setters
    void setCurrentScreen(std::string* screen);
    void setPrevScreen(std::string* screen);

    // Interaction with MainMenuScreen
    void showMainMenu();
};
