

#include "ResourceScreen.h"

ResourceScreen::ResourceScreen() :processName("A process"), currLine(0), totalLines(100) {

	// Get current time
	time_t now = time(nullptr);
	tm localTime;
	
	localtime_s(&localTime, &now);


	// Format the timestamp
	char timestampBuffer[24]; 
	size_t bufferSize = sizeof(timestampBuffer);
	strftime(timestampBuffer, bufferSize, "%m/%d/%Y, %I:%M:%S %p", &localTime);
	creationTimestamp = timestampBuffer;
	
}
ResourceScreen::ResourceScreen(string processName)
	:processName(processName), currLine(0), totalLines(100) {

	// Get current time
	time_t now = time(nullptr);
	tm localTime;
	localtime_s(&localTime, &now);

	// Format the timestamp
	char timestampBuffer[24];
	strftime(timestampBuffer, sizeof(timestampBuffer), "%m/%d/%Y, %I:%M:%S %p", &localTime); 
	creationTimestamp = timestampBuffer;
}

void ResourceScreen::displayHeader() {
	cout << "Process: " << processName << endl;
	cout << "Current instruction line: " << currLine << endl;
	cout << "Total lines: " << totalLines << endl;
	cout << "Creation timestamp: " << creationTimestamp << endl << endl;
}

void ResourceScreen::displayScreen() {
	string input;
	displayHeader();

	cout << "root:\\> ";
	getline(cin, input);

	if (input == "exit") {
		return;
	}
	else {
		cout << "Invalid command." << endl;
	}
}
