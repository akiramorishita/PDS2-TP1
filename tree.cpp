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
    if (!treeNode)
    {
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
    if (node->left != nullptr)
    {
        indiceInvertido(node->left, docMax);
    }
    cout << node->value << " ";
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

vector<float> Tree::cousineRanking(Node *node, int docMax, vector<string> query)
{
    vector<float> sum;
    vector<float> aux;
    cout << " " << q[0] << " ";
    if (node->left != nullptr)
    {
        aux = cousineRanking(node->left, docMax, query);
    }else{
        for (int i = 0; i < docMax; i++){
            aux.push_back(0);
        }
    }

    if (find(query.begin(), query.end(), node->value) != query.end()){
        for (int i = 0; i < docMax; i++){
            sum.push_back(q[0]*node->importance[i]  );
        }
    }else{
        for (int i = 0; i < docMax; i++){
            sum.push_back(0);
        }
    }

    q.push_back(q[0]);
    q.erase(q.begin());

    for (int i = 0; i<(int)aux.size();i++){
        sum[i] += aux[i];
    }

    if (node->right != nullptr)
    {
        aux = cousineRanking(node->right, docMax, query);
    }else{
        for (int i = 0; i < docMax; i++){
            aux.push_back(0);
        }
    }

    transform(sum.begin(),sum.end(),aux.begin(),sum.begin(),plus<float>());

    return sum;
}

vector<float> Tree::getQ(){
    return q;
}