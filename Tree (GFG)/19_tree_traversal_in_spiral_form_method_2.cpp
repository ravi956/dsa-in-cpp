//This method processes every node two times
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

void printSpiral(Node *root)
{
    if (root == NULL)
        return;

    stack<Node *> s1;
    stack<Node *> s2;

    s1.push(root);
    while (s1.empty() == false || s2.empty() == false)
    {
        while (s1.empty() == false)
        {
            Node *curr = s1.top();
            s1.pop();

            cout << curr->data << " ";
            if (curr->left != NULL)
                s2.push(curr->left);
            if (curr->right != NULL)
                s2.push(curr->right);
        }

        while (s2.empty() == false)
        {
            Node *curr = s2.top();
            s2.pop();

            cout << curr->data << " ";
            if (curr->right != NULL)
                s1.push(curr->right);
            if (curr->left != NULL)
                s1.push(curr->left);
        }
    }
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
    printSpiral(root);
    return 0;
}