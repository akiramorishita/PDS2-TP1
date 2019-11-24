//g++ -Wall main.cpp -o main
#include <iostream>
#include <fstream>
#include <vector>
#include "book.h"
#include "tree.h"
using namespace std;

int main()
{
    Book book;
    Tree tree;
    int filenum = 0;
    string filename;
    filename = "file.txt";
    book.readData(filename, tree, filenum);
    filename = "file2.txt";
    filenum++;
    book.readData(filename, tree, filenum);
    filename = "file3.txt";
    filenum++;
    book.readData(filename, tree, filenum);
    filename = "file4.txt";
    filenum++;
    book.readData(filename, tree, filenum);
    filenum++;
    tree.indiceInvertido(tree.getRoot(), filenum);
    return 0;
}
