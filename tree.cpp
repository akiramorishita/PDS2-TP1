#include <iostream>
#include "tree.h"
using namespace std;

Tree::Tree()
{
    root_ = NULL;
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

void Tree::insert(Node *treeNode, char value)
{
    if (!treeNode)
    {
        treeNode = new Node(value);
        root_ = treeNode;
    }
    else
    {
        if (value < treeNode->value)
        {
            if (!treeNode->left)
            {
                treeNode->left = new Node(value);
            }
            else
            {
                insert(treeNode->left, value);
            }
        }
        else if (value > treeNode->value)
        {
            if (!treeNode->right)
            {
                treeNode->right = new Node(value);
            }
            else
            {
                insert(treeNode->right, value);
            }
        }
        else
        {
            treeNode->count++;
        }
    }
}

Node* Tree::getRoot()
{
    return root_;
}

int Tree::getValue(Node *node)
{
    return node->value;
}

int Tree::getCount(Node *node)
{
    return node->count;
}