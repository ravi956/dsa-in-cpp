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

// Time complexity => O(n)
// Space complexity => O(n)
bool isPairSum(Node *root, int sum, unordered_set<int> &s)
{
    if (root == NULL)
        return false;

    if (isPairSum(root->left, sum, s) == true)
        return true;

    if (s.find(sum - root->data) != s.end())
        return true;
    else
        s.insert(root->data);

    return isPairSum(root->right, sum, s);
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
    unordered_set<int> s;
    cout << isPairSum(root, 22, s) << endl;
    cout << isPairSum(root, 40, s);
    return 0;
}