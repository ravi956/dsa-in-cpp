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

int res = 0;

int burnTree(Node *root, int leaf, int &dist)
{
    if (root == NULL)
        return 0;

    if (root->data == leaf)
    {
        dist = 0;
        return 1;
    }

    int ldist = -1, rdist = -1;
    int lh = burnTree(root->left, leaf, ldist);
    int rh = burnTree(root->right, leaf, rdist);

    if (ldist != -1)
    {
        dist = ldist + 1;
        res = max(res, dist + rh);
    }
    else if (rdist != -1)
    {
        dist = rdist + 1;
        res = max(res, dist + lh);
    }
    return max(lh, rh) + 1;
}

/*
                    10
                   /  \
                  2    8
                 / \    \
                1   6    9
                     \
                      5
*/

int main()
{
    Node *root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->right->right = new Node(9);
    root->left->right->right = new Node(5);
    int leaf = 1;
    int dist = -1;
    burnTree(root, leaf, dist);
    cout << res;
    return 0;
}