#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int k)
    {
        data = k;
        left = right = NULL;
    }
};

int maxLevel = 0;
void printLeft(Node *root, int level)
{
    if (root == NULL)
        return;

    if (maxLevel < level)
    {
        cout << root->data << " ";
        maxLevel = level;
    }
    printLeft(root->left, level + 1);
    printLeft(root->right, level + 1);
}
void printLeftView(Node *root)
{
    printLeft(root, 1);
}

/*
                    10
                   /  \
                  20   30
                 / \    \
                40 50   70
*/

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->right = new Node(70);
    printLeftView(root);
    return 0;
}