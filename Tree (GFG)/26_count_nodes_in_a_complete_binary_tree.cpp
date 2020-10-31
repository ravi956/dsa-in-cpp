//Time complexity => O(Log n * Log n) which is better than naive
//method of having complexity => O(n) , where n is no. of nodes

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

int countNode(Node *root)
{
    int lh = 0, rh = 0;
    Node *curr = root;
    while (curr != NULL)
    {
        lh++;
        curr = curr->left;
    }
    curr = root;
    while (curr != NULL)
    {
        rh++;
        curr = curr->right;
    }

    if (lh == rh)
        return pow(2, lh) - 1;

    return 1 + countNode(root->left) + countNode(root->right);
}

/*
                    10
                   /  \
                  2    8
                 / \   /
                1   6 9
*/

int main()
{
    Node *root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->right->left = new Node(9);
    cout << countNode(root);
    return 0;
}