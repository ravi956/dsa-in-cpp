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

    int temp = max(l, r) + 1;
    int ans = max(temp, l + r + 1);
    res = max(res, ans);

    return temp;
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
    Node* root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->left->right = new Node(1);
    root->right->right = new Node(8);
    root->left->right->right = new Node(5);
    int diameter = INT_MIN;
    solve(root, diameter);
    cout << diameter << "\n";
    return 0;
}