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

// Time Complexity => O(nLog(hd) + h)
// Space Complexity => O(hd + h)
// hd -> total no. of possible horizontal distance

void vSumR(Node *root, int hd, map<int, int> &mp)
{
    if (root == NULL)
        return;
    vSumR(root->left, hd - 1, mp);
    mp[hd] += root->data;
    vSumR(root->right, hd + 1, mp);
}

void vSum(Node *root)
{
    map<int, int> mp;
    vSumR(root, 0, mp);
    for (auto sum : mp)
        cout << sum.second << " ";
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
    vSum(root);
    return 0;
}