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

    int temp = max(max(l, r) + root->data, root->data);
    int ans = max(temp, l + r + root->data);
    res = max(res, ans);

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