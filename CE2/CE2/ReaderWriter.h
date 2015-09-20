#pragma once
#ifndef READERWRITER_H
#define READERWRITER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class ReaderWriter {
private:
	string _filename;
	ifstream _inputfile;
	ofstream _outputfile;

public:
	ReaderWriter(string filename);
	bool isFileExist();
	vector<string> readFromFile(vector<string>&);
	void writeToFile(vector<string>&);
};

#endif