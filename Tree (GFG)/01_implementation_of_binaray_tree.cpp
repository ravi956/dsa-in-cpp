#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

/*
                    10
                   /  \
                  20   30
                 /
                40
*/

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    cout << root->key << endl;
    cout << root->left->key << " " << root->right->key << endl;
    cout << root->left->left->key << endl;
    return 0;
}