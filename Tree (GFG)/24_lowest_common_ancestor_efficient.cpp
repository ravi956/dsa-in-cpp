//This solution requires one traversal of tree, time complexity => Theta(n)
//It requires extra space of Theta(h) for recursive traversal, h-> height of tree
//It assumes that both n1 and n2 exists in tree. It does not give correct
//result when only one (n1 or n2) exists.
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

Node *lca(Node *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;

    if (root->data == n1 || root->data == n2)
        return root;

    Node *lca1 = lca(root->left, n1, n2);
    Node *lca2 = lca(root->right, n1, n2);

    if (lca1 != NULL && lca2 != NULL)
        return root;

    if (lca1 != NULL)
        return lca1;
    else
        return lca2;
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
    int n1 = 6;  //first node
    int n2 = 18; //second node
    Node *lca_node = lca(root, n1, n2);
    if (lca_node != NULL)
        cout << lca_node->data;
    else
        cout << "No lowest common ancestor exists...";
    return 0;
}