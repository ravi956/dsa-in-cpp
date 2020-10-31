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

bool isCsum(Node *root)
{
    if (root == NULL)
        return true;

    if (root->left == NULL && root->right == NULL)
        return true;

    int sum = 0;
    if (root->left != NULL)
        sum += root->left->data;
    if (root->right != NULL)
        sum += root->right->data;
    return (root->data == sum && isCsum(root->left) && isCsum(root->right));
}

/*
                    10
                   /  \
                  2    8
                 / \    \
                1   1    8
*/

int main()
{
    Node *root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->left->right = new Node(1);
    root->right->right = new Node(8);
    cout << isCsum(root);
    return 0;
}