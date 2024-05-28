#pragma once

#include <string>

// TODO: Please put the functions in the .cpp file

class ConsoleManager
{

private:
    std::string* currentScreen;
    std::string* prevScreen;

public:
    // Constructor
    ConsoleManager(std::string* initialScreen = nullptr)
        : currentScreen(initialScreen), prevScreen(nullptr) {}

    // Destructor
    ~ConsoleManager() {
        // Optionally handle cleanup if you are responsible for the memory
        // delete currentScreen;
        // delete prevScreen;
    }

    // Getters
    const std::string* getCurrentScreen() const {
        return currentScreen;
    }

    const std::string* getPrevScreen() const {
        return prevScreen;
    }

    // Setters
    void setCurrentScreen(std::string* screen) {
        prevScreen = currentScreen; // Update prevScreen to currentScreen pointer
        currentScreen = screen;     // Update currentScreen to new screen pointer
    }

    void setPrevScreen(std::string* screen) {
        prevScreen = screen;
    }
};

