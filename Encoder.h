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
	map<char, int> frequencies;
	vector<pair<char, int>> sortedFrequencies;
	priority_queue<Node*, vector<Node*>, comp> priorityQueue;

	void loadText();
	void encode(Node* root, string str, unordered_map<char, string>& huffmanCode);

public:
	Encoder(string filename, string outputFile);
	string getInputText();
	void setFrequencies();
	void printFrequencies();
	void setSortedFrequencies();
	Node* getNode(char ch, int freq, Node* left, Node* right);
	void buildHuffmanTree();
};

