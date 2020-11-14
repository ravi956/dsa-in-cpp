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
// Space complexity => O(1)
Node *floor(Node *root, int x)
{
    Node *potFloor = NULL;

    while (root != NULL)
    {
        if (root->data == x)
        {
            potFloor = root;
            break;
        }
        else if (root->data < x)
        {
            potFloor = root;
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return potFloor;
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
    Node *floorNode = floor(root, 14);
    if (floorNode != NULL)
        cout << floorNode->data << endl;
    else
        cout << "NULL";
    return 0;
}