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

// Method 1
// Time Complexity => O(n)
// Space Complexity => O(h)
bool isBST1(Node *root, int min, int max)
{
    if (root == NULL)
        return true;

    return (root->data > min && root->data < max && isBST1(root->left, min, root->data) && isBST1(root->right, root->data, max));
}

// Method 2
// Time Complexity => O(n)
// Space Complexity => O(h)
int prev = INT_MIN;
bool isBST2(Node *root)
{
    if (root == NULL)
        return true;
    if (isBST2(root->left) == false)
        return false;
    if (root->data <= ::prev)
        return false;
    ::prev = root->data;
    return isBST2(root->right);
}

/*
                    10
                   /  \
                  5    15
                 / \    \
                1   6    17
                     \
                      7
*/

int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    // root->right->left = new Node(8);
    root->right->right = new Node(17);
    root->left->right->right = new Node(7);
    cout << isBST1(root, INT_MIN, INT_MAX) << endl;
    cout << isBST2(root);
    return 0;
}