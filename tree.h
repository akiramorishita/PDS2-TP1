#ifndef TREE
#define TREE
#include <iostream>
#include <vector>
using namespace std;

// Representa um número complexo.
struct Node
{
    Node(string value, int docNumber) {
        this->value=value;
        left = nullptr;
        right = nullptr;
        for(int i = 0; i < docNumber; i++)
            count.push_back(0);
        count.push_back(1);
    };
    string value;
    vector<int> count;
    Node *left;
    Node *right;
};

class Tree
{
public:
    Tree();
    ~Tree();

    void insert(string value, int docNumber)
    {
        insert(root_, value, docNumber);
    }

    void deleteTree()
    {
        deleteTree(root_);
    }

    Node *getRoot();

    string getValue(Node *node);

    int getCount(Node *node, int docNumber);

private:
    Node *root_;
    void insert(Node *treeNode, string value, int docNumber);
    void deleteTree(Node *treeNode);
};

#endif