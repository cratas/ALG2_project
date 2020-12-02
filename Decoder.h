#pragma once
#include <iostream>
#include "Node.h"
#include <queue>
#include <map>

using namespace std;

class Decoder
{
private:
	string inputFile;
	string outputFile;
	string decodedString;
	map<char, string> codes;
	map<char, int> frequencies;

public:
	Decoder(string inputFile, string outputFile, map<char, int> frequencies);
	void createHuffmanCode();
	priority_queue<Node*, vector<Node*>, comp> priorityQueue;
	Node* getNode(char ch, int freq, Node* left, Node* right);
	void storeCodes(struct Node* root, string str);
	void decode(string s);
	string getDecodedString();
};

