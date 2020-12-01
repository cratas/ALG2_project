#include "Encoder.cpp"

using namespace std;

void printCorrectFormat()
{
    cout << "---------------------------------------" << endl;
    cout << "Correct commands to run program" << endl;
    cout << "---------------------------------------" << endl;
    cout << "computil c input.txt output.huff" << endl;
    cout << "computil d input.huff output.txt" << endl;
}

int main(int argc, char** argv)
{
    if (argc < 4)
    {
        printCorrectFormat();
        exit(0);
    }
    
    
    if (argv[1][0] == 'c')
    {
        Encoder* e = new Encoder(argv[2], argv[3]);

        cout << e->getInputText() << endl;
        e->setFrequencies();
        e->printFrequencies();
        e->setSortedFrequencies();
        e->buildHuffmanTree();
    }
    else if(argv[1][0] == 'd')
    {
        cout << "nene" << endl;
    }
    else
    {
        printCorrectFormat();
        exit(0);
    }
    
    
    return 0;
}

