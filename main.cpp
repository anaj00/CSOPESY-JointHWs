#include "ConsoleManager.h"
#include "MainMenuScreen.h"

int main() {
    MainMenuScreen mainMenu;
    ConsoleManager consoleManager(nullptr, &mainMenu);
    consoleManager.startConsole();

    return 0;
}
