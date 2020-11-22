#pragma once
#include <iostream>
#include <map>
using namespace std;

class Encoder
{
private:
	string filename;
	string inputText;
	map<char, int> frequencies;
	
	void loadText();
	

public:
	Encoder(string filename);
	string getInputText();
	void setFrequencies();
	void printFrequencies();
	void sortFrequencies();
};

