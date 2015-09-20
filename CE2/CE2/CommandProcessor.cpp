#include "CommandProcessor.h"

CommandProcessor::CommandProcessor() {
	_filename = "";
	_textInputs.clear();
}

CommandProcessor::CommandProcessor(string filename) {
	_filename = filename;
	_textInputs.clear();
}

void CommandProcessor::addText(string filename) {
	string newInput;
	getline(cin, newInput);

	//substr is to trim the white space in front of newInput
	newInput = trimText(newInput);

	_textInputs.push_back(newInput);
	cout << MESSAGE_ADD << filename << MESSAGE_DIVIDER << "\"" << newInput << "\"" << endl;
}

string CommandProcessor::trimText(string text) {
	text = text.substr(INDEX_TRIM_START, text.length() - 1);
	return text;
}

void CommandProcessor::displayText(string filename) {
	if (_textInputs.empty()) {
		cout << filename << MESSAGE_DISPLAY_EMPTY << endl;
	}
	else {
		for (int i = 0; i < _textInputs.size(); i++)
			cout << i + 1 << ". " << _textInputs[i] << endl;
	}
	return;
}

void CommandProcessor::deleteText(string filename) {
	int num;
	cin >> num;

	string deletedText;
	deletedText = _textInputs[num - 1];
	_textInputs.erase(_textInputs.begin() + num - 1);
	cout << MESSAGE_DELETE << filename << MESSAGE_DIVIDER << "\"" << deletedText << "\"" << endl;

	return;
}

void CommandProcessor::clearText(string filename) {
	while (!_textInputs.empty()) {
		_textInputs.pop_back();
	}
	cout << MESSAGE_CLEAR << filename << endl;
}

vector<string> CommandProcessor::getTextInputs()
{
	return _textInputs;
}

void CommandProcessor::setTextInputs(vector<string>& textInputs) {
	_textInputs.swap(textInputs);
	return;
}

void CommandProcessor::sortText() {
	multiset<string> sortedText;
	multiset<string>::iterator it;

	for (int i = 0; i < _textInputs.size(); i++) {
		sortedText.insert(_textInputs[i]);
	}
	
	_textInputs.clear();

	for (it = sortedText.begin(); it != sortedText.end(); it++) {
		_textInputs.push_back(*it);
	}

	sortedText.clear();
}
