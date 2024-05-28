#include "ConsoleManager.h"

// Constructor
ConsoleManager::ConsoleManager(std::string* initialScreen, MainMenuScreen* mainMenuScreen)
    : currentScreen(initialScreen), prevScreen(nullptr), mainMenuScreen(mainMenuScreen) {}

// Destructor
ConsoleManager::~ConsoleManager() {
    // Optionally handle cleanup if you are responsible for the memory
    // delete currentScreen;
    // delete prevScreen;
}

// Interaction with MainMenuScreen
void ConsoleManager::startConsole() {
    bool flag = false;
    if (!flag) {
        flag = mainMenuScreen->process();
    }
}

// Getters
const std::string* ConsoleManager::getCurrentScreen() const {
    return currentScreen;
}

const std::string* ConsoleManager::getPrevScreen() const {
    return prevScreen;
}

// Setters
void ConsoleManager::setCurrentScreen(std::string* screen) {
    prevScreen = currentScreen; // Update prevScreen to currentScreen pointer
    currentScreen = screen;     // Update currentScreen to new screen pointer
}

void ConsoleManager::setPrevScreen(std::string* screen) {
    prevScreen = screen;
}


