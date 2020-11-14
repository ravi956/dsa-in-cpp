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

// To check if the tree is a bst
bool isBST1(Node *root, int min, int max)
{
    if (root == NULL)
        return true;

    return (root->data > min && root->data < max && isBST1(root->left, min, root->data) && isBST1(root->right, root->data, max));
}

// To find the nodes to be swapped
// Time Complexity => O(n)
// Space Complexity => O(h)
Node *prev = NULL, *first = NULL, *second = NULL;

void fixBST(Node *root)
{
    if (root == NULL)
        return;

    fixBST(root->left);
    if (::prev != NULL && root->data < ::prev->data)
    {
        if (first == NULL)
            first = ::prev;
        second = root;
    }
    ::prev = root;
    fixBST(root->right);
}

/*
                    10
                   /  \
                  5    15
                 / \    \
                1  [17]  [6]
                     \
                      7
*/

int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(1);
    root->left->right = new Node(17);
    root->right->right = new Node(6);
    root->left->right->right = new Node(7);
    cout << isBST1(root, INT_MIN, INT_MAX) << endl;
    fixBST(root);
    cout << first->data << " " << second->data << endl;
    swap(first->data, second->data);
    cout << isBST1(root, INT_MIN, INT_MAX) << endl;
    return 0;
}