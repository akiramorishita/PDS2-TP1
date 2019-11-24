#include <iostream>
#include <fstream>
#include "book.h"
#include "tree.h"
#include <cmath>
using namespace std;

void Book::readData(string filename, Tree &tree)
{
    fstream file;
    string word;

    // opening file
    file.open(filename.c_str());

    // extracting words from the file
    while (file >> word)
    {
        // displaying content
        transformWord(word);
        addWord(word, tree);
    }

    return;
}

void Book::transformWord(string &word)
{
    string result;
    for (unsigned int i = 0; i < word.length(); ++i)
    {
        if (word[i] >= 65 && word[i] <= 90)
        {
            word[i] += 32;
            result += word[i];
        }
        else
        {
            if ((word[i] >= 97 && word[i] <= 122) || (word[i] >= 48 && word[i] <= 57))
            {
                result += word[i];
            }
        }
    }
    word = result;
    return;
}

void Book::addWord(string word, Tree &tree)
{
    tree.insert(word);
    return;
}