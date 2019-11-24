#include <iostream>
#include "tree.h"
using namespace std;

Tree::Tree()
{
    root_ = nullptr;
}

void Tree::deleteTree(Node *treeNode)
{
    if (!treeNode)
    {
        return;
    }
    Node *thisLeaf = treeNode;
    Node *leftLeaf = treeNode->left;
    Node *rightLeaf = treeNode->right;
    delete (thisLeaf);
    deleteTree(leftLeaf);
    deleteTree(rightLeaf);
}

Tree::~Tree()
{
    deleteTree(root_);
}

void Tree::insert(Node *treeNode, string value, int docNumber)
{
    if (!treeNode)
    {
        cout << "Entrou em Novo" << endl;
        treeNode = new Node(value, docNumber);
        root_ = treeNode;
    }
    else
    {
        cout << "Entrou em insert" << endl;
        cout << "value = " << value << endl;
        cout << "node->value = " << treeNode->value << endl;
        if (value < treeNode->value)
        {
            if (!treeNode->left)
            {
                treeNode->left = new Node(value, docNumber);
            }
            else
            {
                insert(treeNode->left, value, docNumber);
            }
        }
        else if (value > treeNode->value)
        {
            if (!treeNode->right)
            {
                treeNode->right = new Node(value, docNumber);
            }
            else
            {
                insert(treeNode->right, value, docNumber);
            }
        }
        else
        {
            for (int i = treeNode->count.size()-1;i<docNumber;i++){
                treeNode->count.push_back(0);
            }
            if (treeNode->count.size()<=docNumber){
                treeNode->count.push_back(0);
            }
            treeNode->count[docNumber]++;
        }
    }
}

Node *Tree::getRoot()
{
    return root_;
}

string Tree::getValue(Node *node)
{
    return node->value;
}

int Tree::getCount(Node *node, int docNumber)
{
    return node->count[docNumber];
}