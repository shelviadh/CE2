#include "CommandProcessor.h"
#include "ReaderWriter.h"
#include <vector>

using namespace std;

//command from the users has to be one of these constant strings
const string COMMAND_ADD = "add";
const string COMMAND_DISPLAY = "display";
const string COMMAND_DELETE = "delete";
const string COMMAND_CLEAR = "clear";
const string COMMAND_EXIT = "exit";

//general messages used
const string MESSAGE_WELCOME = "Welcome to TextBuddy. ";
const string MESSAGE_FILE_STATUS = " is ready for use.";
const string MESSAGE_COMMAND_REQUEST = "command: ";

void printWelcomeMessage(string filename);
string commandRequest();

int main(int argc, char* argv[]) {
	string filename;
	cin >> filename;
	
	printWelcomeMessage(filename);

	ReaderWriter readWrite(filename);
	CommandProcessor cmdProcessor(filename);

	string command;

	if (readWrite.isFileExist()) {
		vector<string> textInputs;
		//existing .txt file is loaded to textInputs
		textInputs = readWrite.readFromFile(textInputs);
		cmdProcessor.setTextInputs(textInputs);
	}

	while (true) {
		string commmand;
		command = commandRequest(); //request command from user

		// processing the command given
		if (command == COMMAND_ADD) {
			cmdProcessor.addText(filename);
		}
		else if (command == COMMAND_DISPLAY) {
			cmdProcessor.displayText(filename);
		}
		else if (command == COMMAND_DELETE) {
			cmdProcessor.deleteText(filename);
		}
		else if (command == COMMAND_CLEAR) {
			cmdProcessor.clearText(filename);
		}
		else if (command == COMMAND_EXIT) {
			vector<string> textInputs;
			textInputs = cmdProcessor.getTextInputs();
			readWrite.writeToFile(textInputs);
			break;
		}
	}

	return 0;
}

void printWelcomeMessage(string filename) {
	cout << MESSAGE_WELCOME << filename << MESSAGE_FILE_STATUS << endl;
}

string commandRequest() {
	string command;

	cout << MESSAGE_COMMAND_REQUEST;
	cin >> command;

	return command;
}
