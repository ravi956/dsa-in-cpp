//Precompute height of every node and store it in a map
//Better Solution , Time Complexity = O(n)
//It also requires aux space of O(n) for storing heights in map
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

int height(Node *root, unordered_map<Node *, int> &hNode)
{
    if (root == NULL)
        return 0;

    return hNode[root] = 1 + max(height(root->left, hNode), height(root->right, hNode));
}

int diameter(Node *root, unordered_map<Node *, int> hNode)
{
    if (root == NULL)
        return 0;

    int lh = hNode[root->left];
    int rh = hNode[root->right];

    return max({1 + lh + rh, diameter(root->left, hNode), diameter(root->right, hNode)});
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

    unordered_map<Node *, int> hNode;
    height(root, hNode);
    cout << diameter(root, hNode);
    return 0;
}