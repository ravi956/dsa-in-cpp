//This method doesn't require map, instead it includes
//some modification in the usual code of finding height
//Efficient soln, Time Complexity = O(n)
//Space complexity = O(h) -> like normal tree traversal

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

int diameter = 0;
int height(Node *root)
{
    if (root == NULL)
        return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    diameter = max(diameter, lh + rh + 1);
    return 1 + max(lh, rh);
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
    height(root);
    cout << diameter;
    return 0;
}