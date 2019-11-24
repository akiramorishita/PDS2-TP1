#ifndef BOOK
#define BOOK
#include <iostream>
#include "tree.h"
using namespace std;

// Representa um número complexo.
class Book
{
public:
    void readData(string filename, Tree &tree, int filenum);
    void transformWord(string &word);
    void addWord(string word, Tree &tree, int filenum);

private:
};

#endif
