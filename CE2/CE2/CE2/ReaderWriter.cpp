#include "ReaderWriter.h"

ReaderWriter::ReaderWriter(string filename) {
	_filename = filename;
	_inputfile.open(filename);
}

bool ReaderWriter::isFileExist() {
	if (_inputfile.is_open())
		return true;
	else
		return false;
}

vector<string> ReaderWriter::readFromFile(vector<string>& textInputs) {
	string text;
	while (getline(_inputfile, text)) {
		text = text.substr(3, text.length() - 1);
		textInputs.push_back(text);
	}
	return textInputs;
}

void ReaderWriter::writeToFile(vector<string> &textInputs) {
	_outputfile.open(_filename);

	for (int i = 0; i<textInputs.size(); i++)
		_outputfile << i + 1 << ". " << textInputs[i] << endl;

	_outputfile.close();
	_inputfile.close();

	return;
}