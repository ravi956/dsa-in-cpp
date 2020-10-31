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

// int height(Node *root)
// {
//     // Your code here
//     if (root == NULL)
//         return 0;
//     return 1 + max(height(root->left), height(root->right));
// }

// Time Complexity = O(n*n)
// bool isBalanced(Node *root)
// {
//     if (root == NULL)
//         return true;

//     if (abs(height(root->left) - height(root->right)) > 1)
//         return false;

//     return isBalanced(root->left) && isBalanced(root->right);
// }

//Time Complexity = O(n)
int isBalanced(Node *root)
{
    if (root == NULL)
        return 0;

    int lh = isBalanced(root->left);
    if (lh == -1)
        return -1;
    int rh = isBalanced(root->right);
    if (rh == -1)
        return -1;

    if (abs(lh - rh) > 1)
        return -1;
    else
        return 1 + max(lh, rh);
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
    string result = isBalanced(root) == -1 ? "False" : "True";
    cout << result;
    return 0;
}