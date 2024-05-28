#include "MainMenuScreen.h"
#include "ResourceScreen.h"

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

bool MainMenuScreen::processCommand(const std::string& command) {
    std::istringstream iss(command); // Create a string stream from the command
    std::string token;
    std::string cmd;
    std::string option;
    std::string argument;

    if (iss >> cmd) {
        if (cmd == "screen") {
            iss >> option >> argument; // Read the next two tokens (option and argument)

            if (option == "-r" || option == "-s") {

                std::cout << "screen -r " << argument << " command recognized. Doing something.\n";
                if (screens.find(argument) != screens.end()) {
                    // Redraw the existing screen
                    screens[argument].displayScreen();
                }

                else {
                    // Create a new screen and display it
                    ResourceScreen newScreen(argument);
                    screens[argument] = newScreen;
                    screens[argument].displayScreen();
                }
            }
            /* else if (option == "-s") {
                
            }*/

            else {
                std::cout << "screen not command recognized. Doing something.\n";
                // Add your specific handling for screen here
            }
        }
        else if (cmd == "marquee" || cmd == "process-smi" || cmd == "nvidia-smi" || cmd == "clear" || cmd == "exit") {
            std::cout << cmd << " command recognized. Doing something.\n";

            if (cmd == "clear") {
                system("cls"); // Use "clear" if on a Unix-like system
                printHeader(); // Print the header after clearing the screen
            }
            else if (cmd == "exit") {
                std::cout << "Thank you for using CSOPESY command line interface. Goodbye\n";
                return true;
            }
        }
        else {
            std::cout << "Invalid command.\n";
        }
    }

    return false;
}

bool MainMenuScreen::process() {
    std::string command;
    printHeader(); // Initial print of the header

    bool flag = false;
    while (!flag) {
        std::cout << "Enter a command: ";
        std::getline(std::cin, command);
        flag = processCommand(command);
        system("cls");
        printHeader();
    }

    return true;
}