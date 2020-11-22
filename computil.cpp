#include "Encoder.h"
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
    
    Encoder* e = new Encoder("input.txt");

    cout << e->getInputText() << endl;
    e->setFrequencies();
    //e->printFrequencies();
    e->sortFrequencies();
    return 0;
}

