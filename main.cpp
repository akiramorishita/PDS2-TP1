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
    string filename = "file.txt";
    book.readData(filename,tree,filenum);
    cout << 100 << endl;
    cout << tree.getValue(tree.getRoot()) << endl;
    cout << tree.getCount(tree.getRoot(),filenum) << endl;
    cout << 101 << endl;
    cout << tree.getValue(tree.getRoot()->right) << endl;
    cout << tree.getCount(tree.getRoot()->right,filenum) << endl;
    cout << 102 << endl;
    cout << tree.getValue(tree.getRoot()->left) << endl;
    cout << tree.getCount(tree.getRoot()->left,filenum) << endl;
    return 0;
    /*Tree tree;
    tree.insert('c');
    tree.insert('c');
    tree.insert('c');
    tree.insert('b');
    tree.insert('b');
    tree.insert('b');
    tree.insert('b');
    Node *result = tree.getRoot();
    int count = tree.getCount(result);
    char value = tree.getValue(result);
    std::cout << value << " " << count;
    return 0;*/
}
