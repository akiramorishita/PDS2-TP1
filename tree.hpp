#ifndef TREE
#define TREE
#include <iostream>
using namespace std;

// Representa um número complexo.
struct Node {
    Node(char value): value(value), count(0), left(NULL), right(NULL) {};
    char value;
    int count;
    Node* left;
    Node* right;
};

class Tree
{
public:
    Tree();
    ~Tree();

    void insert(char value) {
        insert(root_, value);
    }

    void deleteTree() {
        deleteTree(root_);
    }

    char getRoot() {
        return getRoot(root_);
    }

private:
    Node *root_;
    void insert(Node* treeNode, char value);
    void deleteTree(Node* treeNode);
    char getRoot(Node* treeNode);
};

#endif