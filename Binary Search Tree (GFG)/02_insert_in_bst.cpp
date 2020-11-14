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

// Time complexity => O(h)
// Space complexity => O(h)
Node *insertRec(Node *root, int x)
{
    if (root == NULL)
        return new Node(x);
    else if (root->data < x)
        root->right = insertRec(root->right, x);
    else if (root->data > x)
        root->left = insertRec(root->left, x);
    return root;
}

// Time complexity => O(h)
// Space complexity => O(1)
Node *insertIt(Node *root, int x)
{
    Node *temp = new Node(x);

    Node *parent = NULL, *curr = root;
    while (curr != NULL)
    {
        parent = curr;
        if (curr->data > x)
            curr = curr->left;
        else if (curr->data < x)
            curr = curr->right;
        else
            return root;
    }

    if (parent == NULL)
        return temp;
    if (parent->data > x)
        parent->left = temp;
    else
        parent->right = temp;

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
    root = insertIt(root, 0);
    root = insertIt(root, 4);
    root = insertIt(root, 17);
    // root = insertRec(root, 0);
    // root = insertRec(root, 4);
    // root = insertRec(root, 17);
    printLevel(root);
    return 0;
}