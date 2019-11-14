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
    tree.insert('b');
    char result = tree.getRoot();
    std::cout << result;
    return 0;
}
