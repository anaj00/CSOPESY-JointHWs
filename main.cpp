#include "ConsoleManager.h"
#include "MainMenuScreen.h"

int main() {
    MainMenuScreen mainMenu;
    ConsoleManager consoleManager(nullptr, &mainMenu);
    consoleManager.showMainMenu();

    return 0;
}
