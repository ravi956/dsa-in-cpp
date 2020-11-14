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

// Time complexity => O(h)
// Space complexity => O(h)
bool searchRec(Node *root, int x)
{
    if (root == NULL)
        return false;

    if (root->data == x)
        return true;
    else if (root->data < x)
        return searchRec(root->right, x);
    else
        return searchRec(root->left, x);
}

// Time complexity => O(h)
// Space complexity => O(1)
bool searchIt(Node *root, int x)
{
    while (root != NULL)
    {
        if (root->data == x)
            return true;
        else if (root->data < x)
            root = root->right;
        else
            root = root->left;
    }
    return false;
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
    root->right->right = new Node(17);
    root->left->right->right = new Node(7);
    cout << searchRec(root, 6) << endl;
    cout << searchRec(root, 18) << endl;
    cout << searchIt(root, 6) << endl;
    cout << searchIt(root, 18) << endl;
    return 0;
}