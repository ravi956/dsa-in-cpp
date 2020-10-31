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

void printAtK(Node *root, int k)
{
    if (root == NULL)
        return;
    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }

    printAtK(root->left, k - 1);
    printAtK(root->right, k - 1);
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
    int k = 2;
    printAtK(root, k);
    return 0;
}