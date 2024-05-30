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
            bool flagFound = false;

            if (option == "-r") {
                bool flagFound = screenExists(argument);
                if (!flagFound) {
                    std::cout << "Screen does not exist create it first" << std::endl;
                }
                else {
                    screens[argument].displayScreen();
                }
            }
            else if (option == "-s") {
                bool flagFound = screenExists(argument);
                if (!flagFound) {
                    ResourceScreen newScreen(argument);
                    screens[argument] = newScreen;
                    screens[argument].displayScreen();
                }
                else {
                    std::cout << "Screen already exists." << std::endl;
                }
               
            }
          
            else {
                std::cout << "screen command not recognized. Doing something." << std::endl;

            }
        }
        else if (cmd == "marquee" || cmd == "process-smi" || cmd == "nvidia-smi" || cmd == "clear" || cmd == "exit") {
            std::cout << cmd << " command recognized. Doing something." << std::endl;

            if (cmd == "clear") {
                system("cls"); 
                printHeader(); 
            }
            else if (cmd == "exit") {
                std::cout << "Thank you for using CSOPESY command line interface. Goodbye" << std::endl;
                return true;
            }
        }
        else {
            std::cout << "Invalid command" << std::endl;
        }
    }

    return false;
}

bool MainMenuScreen::screenExists(const std::string& name) {
    for (const auto& pair : screens) {
        if (pair.first == name) { // Compare std::string objects using ==
            std::cout << name << " found\n";
            return true;
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
       
    }

    return true;
}