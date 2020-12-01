#include "Encoder.h"


Encoder::Encoder(string inputFile, string outputFile)
{
	this->inputFile = inputFile;
    this->outputFile = outputFile;
    loadText();
}

void Encoder::loadText()
{
    ifstream inputFileStream(inputFile);
    stringstream sstream;
    sstream << inputFileStream.rdbuf();
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
    setSortedFrequencies();
}

void Encoder::printFrequencies()
{
    vector<pair<char, int>>::iterator iterator;

    cout << endl << "CHARACTER    COUNT" << endl;

    for (iterator = sortedFrequencies.begin(); iterator != sortedFrequencies.end(); iterator++)
    {
        cout << "   '" << iterator->first << "'         " << iterator->second << endl;
    }
}

bool cmp(pair<char, int>& a,
    pair<char, int>& b)
{
    return a.second < b.second;
}

void Encoder::setSortedFrequencies()
{
    for (auto& it : frequencies) {
        sortedFrequencies.push_back(it);
    }
    sort(sortedFrequencies.begin(), sortedFrequencies.end(), cmp);
}

Node* Encoder::getNode(char ch, int freq, Node* left, Node* right)
{
    Node* node = new Node();

    node->ch = ch;
    node->freq = freq;
    node->left = left;
    node->right = right;

    return node;
}

void Encoder::encode(Node* root, string str ,unordered_map<char, string>& huffmanCode)
{
    if (root == nullptr)
        return;

    // found a leaf node
    if (!root->left && !root->right) {
        huffmanCode[root->ch] = str;
    }

    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}

void Encoder::buildHuffmanTree() //https://www.techiedelight.com/huffman-coding/
{

    // Create a leaf node for each character and add it
    // to the priority queue.
    for (auto pair : frequencies) {
        priorityQueue.push(getNode(pair.first, pair.second, nullptr, nullptr));
    }

    // do till there is more than one node in the queue
    while (priorityQueue.size() != 1)
    {
        // Remove the two nodes of highest priority
        // (lowest frequency) from the queue
        Node* left = priorityQueue.top(); 
        priorityQueue.pop();

        Node* right = priorityQueue.top();    
        priorityQueue.pop();

        // Create a new internal node with these two nodes
        // as children and with frequency equal to the sum
        // of the two nodes' frequencies. Add the new node
        // to the priority queue.
        int sum = left->freq + right->freq;
        priorityQueue.push(getNode('\0', sum, left, right));
    }

    // root stores pointer to root of Huffman Tree
    Node* root = priorityQueue.top();

    // traverse the Huffman Tree and store Huffman Codes
    // in a map. Also prints them
    unordered_map<char, string> huffmanCode;
    encode(root, "", huffmanCode);

    cout << "Huffman Codes are :\n" << '\n';
    for (auto pair : huffmanCode) {
        cout << pair.first << " " << pair.second << '\n';
    }

    cout << "\nOriginal string was :\n" << inputText << '\n';

    // print encoded string
    string str = "";
    for (char c : inputText) {
        str += huffmanCode[c];
    }

    cout << "\nEncoded string is :\n" << str << '\n';

}



