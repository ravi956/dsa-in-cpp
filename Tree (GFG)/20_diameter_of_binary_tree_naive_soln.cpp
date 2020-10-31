//Naive Solution , Time Complexity = O(n*n)
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

int height(Node *root)
{
    if (root == NULL)
        return 0;

    return 1 + max(height(root->left), height(root->right));
}

int diameter(Node *root)
{
    if (root == NULL)
        return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    return max({1 + lh + rh, diameter(root->left), diameter(root->right)});
}

/*
                    10
                   /  \
                  2    8
                 / \    \
                1   1    8
                     \
                      5
*/

int main()
{
    Node *root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->left->right = new Node(1);
    root->right->right = new Node(8);
    root->left->right->right = new Node(5);
    cout << diameter(root);
    return 0;
}