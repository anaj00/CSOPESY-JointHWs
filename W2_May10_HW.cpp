#include <iostream>
#include <string>
#include <cstdlib> // For system("cls")

void printHeader() {
    std::cout << R"(
                     _________   _________________ _____________________ ______________.___.
                     \_   ___ \ /   _____/\_____  \\______   \_   _____//   _____/\__  |   |
                     /    \  \/ \_____  \  /   |   \|     ___/|    __)_ \_____  \  /   |   |
                     \     \____/        \/    |    \    |    |        \/        \ \____   |
                      \______  /_______  /\_______  /____|   /_______  /_______  / / ______|
                             \/        \/         \/                 \/        \/  \/       
                    )" << std::endl;
}

void processCommand(const std::string& command) {

    if (command == "marquee" || command == "screen" || command == "process-smi" ||
        command == "nvidia-smi" || command == "clear" || command == "exit") {
        std::cout << command << " command recognized. Doing something.\n";

        if (command == "clear") {
            system("cls"); 
            printHeader(); 
        }

        else if (command == "exit") {
            exit(0); // Exit the application
        }
    }
    else {
        std::cout << "Invalid command. \n";
    }
}

int main() {
    std::string command;
    printHeader();
    while (true) {
        std::cout << "Enter a command: ";
        std::cin >> command;
        processCommand(command);
    }
    return 0;
}
