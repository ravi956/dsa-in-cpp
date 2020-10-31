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

int maximum(Node *root)
{
    if (root == NULL)
        return INT_MIN;

    return max({root->data, maximum(root->left), maximum(root->right)});
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
    cout << "Maximum = " << maximum(root);
    return 0;
}