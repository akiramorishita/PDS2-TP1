#include "book.hpp"
#include <cmath>
using namespace std; 

Book::readData()
{
    fstream file;
    string word, t, q, filename;

    // filename of the file
    filename = "file.txt";

    // opening file
    file.open(filename.c_str());

    // extracting words from the file
    while (file >> word)
    {
        // displaying content
        cout << word << endl;
    }

    return 0;
}

Book::translateWord(char *word)
{
}
