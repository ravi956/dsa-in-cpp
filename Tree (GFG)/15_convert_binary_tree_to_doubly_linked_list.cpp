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

Node *BTToDLL(Node *root)
{
    if (root == NULL)
        return root;

    static Node *prev = NULL;

    Node *head = BTToDLL(root->left);

    if (prev == NULL)
        head = root;
    else
    {
        root->left = prev;
        prev->right = root;
    }
    prev = root;

    BTToDLL(root->right);
    return head;
}

/*
                    10
                   /  \
                  5    20
                      / \
                    30   35
*/

int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->right->left = new Node(30);
    root->right->right = new Node(35);
    Node *head = BTToDLL(root);
    Node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->right;
    }
    return 0;
}