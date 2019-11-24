#ifndef TREE
#define TREE

// Representa um número complexo.
struct Node
{
    Node(char value) : value(value), count(1), left(NULL), right(NULL){};
    char value;
    int count;
    Node *left;
    Node *right;
};

class Tree
{
public:
    Tree();
    ~Tree();

    void insert(char value)
    {
        insert(root_, value);
    }

    void deleteTree()
    {
        deleteTree(root_);
    }

    Node* getRoot();

    int getValue(Node *node);

    int getCount(Node *node);

private:
    Node *root_;
    void insert(Node *treeNode, char value);
    void deleteTree(Node *treeNode);
};

#endif