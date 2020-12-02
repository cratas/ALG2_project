#include "Encoder.cpp"
#include "Decoder.cpp"

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

        e->encode();
    }
    else if(argv[1][0] == 'd')
    {
        Encoder* e = new Encoder(argv[2], argv[3]);
        e->encode();
        Decoder* d = new Decoder(argv[2], argv[3], e->getFrequencies());
        d->createHuffmanCode();
        d->decode(e->getEncodedString());
    }
    else
    {
        printCorrectFormat();
        exit(0);
    }
    
    
    return 0;
}

