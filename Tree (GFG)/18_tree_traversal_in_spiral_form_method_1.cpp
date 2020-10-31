//This method processes a single node at most 4 times
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

    queue<Node *> q;
    stack<int> s;
    bool reverse = false;

    q.push(root);
    while (q.empty() == false)
    {
        int count = q.size();

        for (int i = 0; i < count; i++)
        {
            Node *curr = q.front();
            q.pop();

            if (reverse)
                s.push(curr->data);
            else
                cout << curr->data << " ";

            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);
        }

        if (reverse)
        {
            while (s.empty() == false)
            {
                cout << s.top() << " ";
                s.pop();
            }
        }
        reverse = !reverse;
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