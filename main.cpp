//g++ -Wall main.cpp -o main
#include <iostream>
#include <fstream>
#include <vector>
#include "book.hpp"
#include "tree.hpp"

int main()
{
    Tree tree;
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
    return 0;
}
