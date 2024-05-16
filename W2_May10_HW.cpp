#include <iostream>
#include <string>
#include <cstdlib> // for cls

#define RESET "\033[0m"
#define RED "\033[31m"
#define YELLOW "\033[33m"

void printHeader() {
    std::cout << R"(
                     _________   _________________ _____________________ ______________.___.
                     \_   ___ \ /   _____/\_____  \\______   \_   _____//   _____/\__  |   |
                     /    \  \/ \_____  \  /   |   \|     ___/|    __)_ \_____  \  /   |   |
                     \     \____/        \/    |    \    |    |        \/        \ \____   |
                      \______  /_______  /\_______  /____|   /_______  /_______  / / ______|
                             \/        \/         \/                 \/        \/  \/       
    )" << std::endl;

    std::cout << RED << "Hello. Welcome to CSOPESY command line interface.\n" << RESET;
    std::cout << YELLOW << "Type 'exit' to quit, 'clear' to clear the screen.\n" << RESET;
}

void processCommand(const std::string& command) {
    //screen 
    if (command == "screen") {
        std::cout << command << " command recognized. Doing something.\n";
    } else if (command == "marquee" 
            || command == "process-smi" 
            || command == "nvidia-smi" 
            || command == "clear" 
            || command == "exit") {
            
                std::cout << command << " command recognized. Doing something.\n";
        
        if (command == "clear") {
            system("cls"); 
            printHeader(); 
        }

        else if (command == "exit") {
            exit(0);
        }
    }
    else {
        std::cout << "Invalid command.\n";
    }
}

int main() {
    std::string command;
    printHeader();

    while (true) {
        std::cout << "Enter a command: ";
        std::getline(std::cin, command);
        processCommand(command);
    }

    return 0;
}
