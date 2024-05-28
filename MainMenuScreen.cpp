#include "MainMenuScreen.h"
#include <iostream> // Ensure you include this header for std::cout
#include <string>

void MainMenuScreen::printHeader() {
    std::cout << R"(
                     _________   _________________ _____________________ ______________.___.
                     \_   ___ \ /   _____/\_____  \\______   \_   _____//   _____/\__  |   |
                     /    \  \/ \_____  \  /   |   \|     ___/|    __)_ \_____  \  /   |   |
                     \     \____/        \/    |    \    |    |        \/        \ \____   |
                      \______  /_______  /\_______  /____|   /_______  /_______  / / ______|
                             \/        \/         \/                 \/        \/  \/       
    )" << std::endl;

    std::cout << "Hello. Welcome to CSOPESY command line interface.\n";
    std::cout << "Type 'exit' to quit, 'clear' to clear the screen.\n";
}

void MainMenuScreen::processCommand(const std::string& command) {
    if (command == "screen") {
        std::cout << command << " command recognized. Doing something.\n";
    }
    else if (command == "marquee" || command == "process-smi" || command == "nvidia-smi" || command == "clear" || command == "exit") {
        std::cout << command << " command recognized. Doing something.\n";

        if (command == "clear") {
            system("cls"); // Use "clear" if on a Unix-like system
            printHeader(); // Moved here to print the header only after clearing the screen
        }
        else if (command == "exit") {
            std::cout << "Thank you for using CSOPESY command line interface. Goodbye\n";
            exit(0);
        }
    }
    else {
        std::cout << "Invalid command.\n";
    }
}

bool MainMenuScreen::process() {
    std::string command;
    printHeader(); // Initial print of the header

    while (true) {
        std::cout << "Enter a command: ";
        std::getline(std::cin, command);
        processCommand(command); // Header will print again only if "clear" command is used
    }

    return true;
}
