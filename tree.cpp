#include <iostream>
#include "tree.h"
#include <tgmath.h>
#include <iomanip>
#include <algorithm>
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
    cout << treeNode << endl;
    if (!treeNode)
    {
        cout << "novo" << endl;
        treeNode = new Node(value, docNumber);
        root_ = treeNode;
    }
    else
    {
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
            for (int i = treeNode->count.size(); i < docNumber; i++)
            {
                treeNode->count.push_back(0);
            }
            if (int(treeNode->count.size()) <= docNumber)
            {
                treeNode->count.push_back(0);
                addNumDocsAppear(treeNode);
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

void Tree::indiceInvertido(Node *node, int docMax)
{
    cout << node->left << endl;
    cout << node->right << endl;
    if (node->left != nullptr)
    {
        indiceInvertido(node->left, docMax);
    }
    cout << node->value << endl;
    cout << "Q " << log(((float)docMax / (float)node->numDocsAppear)) << endl;
    q.push_back(log(((float)docMax / (float)node->numDocsAppear)));
    for (int i = 0; i < int(node->count.size()); i++)
    {
        if (i == int(node->importance.size()))
        {
            node->importance.push_back(0);
        }
        node->importance[i] = log((float)docMax / (float)node->numDocsAppear) * (float)node->count[i];
        cout << fixed << setprecision(2) << node->importance[i] << "  ";
    }
    for (int i = int(node->count.size()); i < docMax; i++)
    {
        node->count.push_back(0);
        node->importance[i] = 0;
        cout << fixed << setprecision(2) << node->importance[i] << "  ";
    }
    cout << endl;
    if (node->right != nullptr)
    {
        indiceInvertido(node->right, docMax);
    }
    return;
}

void Tree::addNumDocsAppear(Node *node)
{
    node->numDocsAppear += 1;
}

vector<float> Tree::cousineRanking(Node *node, int docMax, vector<string> query, vector<float> W)
{
    vector<float> sum;
    vector<float> aux;
    if (node->left != nullptr)
    {
        aux = cousineRanking(node->left, docMax, query, W);
    }

    if (find(query.begin(), query.end(), node->value) != query.end()){
        for (int i = 0; i < docMax; i++){
            sum.push_back(q[0]*node->importance[i]  );
            q.push_back(q[0]);
            q.erase(q.begin());
        }
    }else{
        for (int i = 0; i < docMax; i++){
            sum.push_back(0);
        }
    }

    transform(sum.begin(),sum.end(),aux.begin(),sum.begin(),plus<float>());

    if (node->right != nullptr)
    {
        aux = cousineRanking(node->right, docMax, query, W);
    }

    transform(sum.begin(),sum.end(),aux.begin(),sum.begin(),plus<float>());

    return sum;
}