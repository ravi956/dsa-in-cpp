#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int k)
    {
        data = k;
        left = right = NULL;
    }
};

int solve(Node* root, int& res)
{
    if (root == NULL)
        return 0;

    int l = solve(root->left, res);
    int r = solve(root->right, res);

    int temp = max(l, r) + root->data;
    if (root->left == NULL && root->right == NULL) // there is no need to check for this condition
        temp = max(temp, root->data); // because this will never occur

    if (root->left != NULL && root->right != NULL)
        res = max(res, l + r + root->data);

    return temp;
}

/*
                    10
                   /  \
                -20    8
                 / \    \
                1   1    8
                     \
                      5
*/

int main()
{
    Node* root = new Node(10);
    root->left = new Node(-20);
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->left->right = new Node(1);
    root->right->right = new Node(8);
    root->left->right->right = new Node(5);
    int res = INT_MIN;
    solve(root, res);
    cout << res << "\n";
    return 0;
}