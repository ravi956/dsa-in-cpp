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

int getMaxWidth(Node *root)
{

    // Your code here

    if (root == NULL)
        return 0;

    queue<Node *> q;
    int maxWidth = 0;
    q.push(root);
    while (q.empty() == false)
    {
        int count = q.size();
        maxWidth = max(maxWidth, count);
        for (int i = 0; i < count; i++)
        {
            Node *curr = q.front();
            q.pop();
            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);
        }
    }
    return maxWidth;
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
    cout << getMaxWidth(root);
    return 0;
}