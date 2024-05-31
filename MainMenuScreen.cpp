#include "MainMenuScreen.h"
#include "ResourceScreen.h"

void MainMenuScreen::printHeader() {
    cout << R"(
                     _________   _________________ _____________________ ______________.___.
                     \_   ___ \ /   _____/\_____  \\______   \_   _____//   _____/\__  |   |
                     /    \  \/ \_____  \  /   |   \|     ___/|    __)_ \_____  \  /   |   |
                     \     \____/        \/    |    \    |    |        \/        \ \____   |
                      \______  /_______  /\_______  /____|   /_______  /_______  / / ______|
                             \/        \/         \/                 \/        \/  \/       
    )" << endl;

    cout << "Hello. Welcome to CSOPESY command line interface.\n";
    cout << "Type 'exit' to quit, 'clear' to clear the screen.\n";
}

bool MainMenuScreen::processCommand(const string& command) {
    istringstream iss(command); // Create a string stream from the command
    string token;
    string cmd;
    string option;
    string argument;

    if (iss >> cmd) {
        if (cmd == "screen") {
            iss >> option >> argument; // Read the next two tokens (option and argument)
            bool flagFound = false;

            if (option == "-r") {
                bool flagFound = screenExists(argument);
                if (!flagFound) {
                    cout << "Screen does not exist create it first" << endl;
                }
                else {
                    system("cls");

                    screens[argument].displayScreen();

                    system("cls");
                    printHeader();
                }
            }
            else if (option == "-s") {
                bool flagFound = screenExists(argument);
                if (!flagFound) {
                    system("cls");

                    ResourceScreen newScreen(argument);
                    screens[argument] = newScreen;
                    screens[argument].displayScreen();

                    system("cls");
                    printHeader();
                }
                else {
                    cout << "Screen already exists." << endl;
                }
               
            }
          
            else {
                cout << "screen command not recognized. Doing something." << endl;

            }
        }
        else if (cmd == "marquee" || cmd == "process-smi" || cmd == "nvidia-smi" || cmd == "clear" || cmd == "exit") {
            cout << cmd << " command recognized. Doing something." << endl;

            if (cmd == "clear") {
                system("cls"); 
                printHeader(); 
            }
            else if (cmd == "exit") {
                cout << "Thank you for using CSOPESY command line interface. Goodbye" << endl;
                return true;
            }
        }
        else {
            cout << "Invalid command" << endl;
        }
    }

    return false;
}

bool MainMenuScreen::screenExists(const string& name) {
    for (const auto& pair : screens) {
        if (pair.first == name) { 
            return true;
        }
    }
    return false;
}


bool MainMenuScreen::process() {
    string command;
    printHeader(); // Initial print of the header

    bool flag = false;
    while (!flag) {
        cout << endl << "Enter a command: ";
        getline(cin, command);
        flag = processCommand(command);
    }

    return true;
}