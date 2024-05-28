

#include "ResourceScreen.h"

ResourceScreen::ResourceScreen() :processName("A process"), currLine(0), totalLines(100) {

	// Get current time
	std::time_t now = std::time(nullptr);
	std::tm localTime;
	localtime_s(&localTime, &now);

	// Format the timestamp
	char timestampBuffer[20];
	std::strftime(timestampBuffer, sizeof(timestampBuffer), "%m/%d/%Y, %I:%M:%S %p", &localTime);
	creationTimestamp = timestampBuffer;
}	
ResourceScreen::ResourceScreen(std::string processName)
	:processName(processName), currLine(0), totalLines(100){

	// Get current time
	std::time_t now = std::time(nullptr);
	std::tm localTime;
	localtime_s(&localTime, &now);

	// Format the timestamp
	char timestampBuffer[20];
	std::strftime(timestampBuffer, sizeof(timestampBuffer), "%m/%d/%Y, %I:%M:%S %p", &localTime);
	creationTimestamp = timestampBuffer;
}

void ResourceScreen::displayHeader() {
	system("cls");
	std::cout << "Process: " << processName << std::endl;
	std::cout << "Current instruction line: " << currLine << std::endl;
	std::cout << "Total lines: " << totalLines << std::endl;
	std::cout << "Creation timestamp: " << creationTimestamp << std::endl << std::endl;
}

void ResourceScreen::displayScreen() {
	std::string input;
	displayHeader();

	std::cout << "root:\\> ";
	std::getline(std::cin, input);

	if (input == "exit") {
		return;
	}
	else {
		std::cout << "Invalid command.\n";
	}
}

