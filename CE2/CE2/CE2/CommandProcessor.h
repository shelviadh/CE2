#pragma once
#ifndef COMMANDPROCESSOR_h
#define COMMANDPROCESSOR_h

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

const int INDEX_TRIM_START = 1;

//messages as response to user commands
const string MESSAGE_ADD = "added to ";
const string MESSAGE_CLEAR = "all content deleted from ";
const string MESSAGE_DISPLAY_EMPTY = " is empty";
const string MESSAGE_DELETE = "deleted from ";
const string MESSAGE_DIVIDER = ": ";

class CommandProcessor {
	private:
		string _filename;
		vector<string> _textInputs;

	public:
		CommandProcessor();
		CommandProcessor(string);
		void addText(string);
		string trimText(string);
		void displayText(string);
		void deleteText(string);
		void clearText(string);
		vector<string> getTextInputs();
		void setTextInputs(vector<string>&);
		void sortText();
};

#endif
