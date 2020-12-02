#pragma once
#include "Node.h"
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <functional>
#include <set>

using namespace std;

class Encoder
{
private:
	string inputFile;
	string outputFile;
	string inputText;
	string encodedString;
	map<char, int> frequencies;
	priority_queue<Node*, vector<Node*>, comp> priorityQueue;
	void loadText();
	void encode(Node* root, string str, unordered_map<char, string>& huffmanCode);
	void setFrequencies();
	Node* getNode(char ch, int freq, Node* left, Node* right);
	void createHuffmanCode();
public:
	Encoder(string filename, string outputFile);
	void encode();
	map<char, int> getFrequencies();
	string getEncodedString();
	
};

