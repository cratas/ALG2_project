#include "Encoder.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <functional>
#include <set>

Encoder::Encoder(string filename)
{
	this->filename = filename;
    loadText();
}

void Encoder::loadText()
{
    ifstream inputFile(filename);
    stringstream sstream;
    sstream << inputFile.rdbuf();
    inputText = sstream.str();
}

string Encoder::getInputText()
{
    return inputText;
}

void Encoder::setFrequencies()
{
    for (char c : inputText)
    {
        frequencies[c]++;
    }

    
   
}

void Encoder::printFrequencies()
{
    

    map<char, int>::iterator iterator;

    cout << endl << "CHARACTER    COUNT" << endl;

    for (iterator = frequencies.begin(); iterator != frequencies.end(); iterator++) 
    {
        cout << "   '" << iterator->first << "'            " << iterator->second << endl;
    }
}

bool cmp(pair<char, int>& a,
    pair<char, int>& b)
{
    return a.second < b.second;
}

void Encoder::sortFrequencies()
{


}


