#include "Decoder.h"

Decoder::Decoder(string inputFile, string outputFile, map<char, int> frequencies)
{
    this->inputFile = inputFile;
    this->outputFile = outputFile;
    this->frequencies = frequencies;
}

Node* Decoder::getNode(char ch, int freq, Node* left, Node* right)
{
    Node* node = new Node();

    node->ch = ch;
    node->freq = freq;
    node->left = left;
    node->right = right;

    return node;
}

void Decoder::createHuffmanCode()
{
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
}

void Decoder::decode(string s)
{
    struct Node* old = priorityQueue.top();
    struct Node* curr = priorityQueue.top();

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0')
            curr = curr->left;
        else
            curr = curr->right;

        // reached leaf node 
        if (curr->left == nullptr && curr->right == nullptr)
        {
            decodedString += curr->ch;
            curr = old;
        }
    }
    // cout<<ans<<endl
    decodedString = decodedString + '\0';
    cout << "decoder: decoded string:" << endl;
    cout << decodedString << endl;
}

string Decoder::getDecodedString()
{
    return decodedString;
}