//g++ -Wall main.cpp -o main
#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>
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
    cout << "  ";

    for (int i = 0;i<filenum;i++){
        cout << "v" << i << "    ";
    }
    cout << endl;
    tree.indiceInvertido(tree.getRoot(), filenum);
    cout << endl;

    vector<float> aux;
    vector<string> query;
    query.push_back("a");
    query.push_back("b");

    cout << "Q:";
    aux = tree.cousineRanking(tree.getRoot(),filenum,query);
    cout << endl << endl;

    //sort(aux.begin(),aux.end());
    for (int i = 0;i<(int)aux.size();i++){
        cout << "Doc" << i+1 <<" Nota: " << aux[i] << endl;
    }
    return 0;
}
