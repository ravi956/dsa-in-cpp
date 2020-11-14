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

// This code works only when there is non empty right child
Node *getSuccessor(Node *curr)
{
    curr = curr->right;
    while (curr != NULL && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}

// Time complexity => O(h)
// Space complexity => O(h)
Node *delNode(Node *root, int x)
{
    if (root == NULL)
        return root;

    if (root->data > x)
        root->left = delNode(root->left, x);
    else if (root->data < x)
        root->right = delNode(root->right, x);
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            Node *succ = getSuccessor(root);
            root->data = succ->data;
            root->right = delNode(root->right, succ->data);
        }
    }
    return root;
}

void printLevel(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    while (q.empty() == false)
    {
        Node *curr = q.front();
        q.pop();
        cout << curr->data << " ";
        if (curr->left != NULL)
            q.push(curr->left);
        if (curr->right != NULL)
            q.push(curr->right);
    }
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
    root = delNode(root, 10);
    printLevel(root);
    return 0;
}