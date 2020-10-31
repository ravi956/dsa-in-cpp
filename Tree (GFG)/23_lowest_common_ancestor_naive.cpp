//This solution requires three traversals of the tree, time complexity => Theta(n)
//It also requires aux space for storing the paths , space complexity => O(n)
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

bool findPath(Node *root, vector<Node *> &p, int n)
{
    if (root == NULL)
        return false;

    p.push_back(root);

    if (root->data == n)
        return true;

    if (findPath(root->left, p, n) || findPath(root->right, p, n))
        return true;

    p.pop_back();
    return false;
}

Node *lca(Node *root, int n1, int n2)
{
    vector<Node *> path1, path2;

    if (findPath(root, path1, n1) == false || findPath(root, path2, n2) == false)
        return NULL;

    for (int i = 0; i < path1.size() - 1 && i < path2.size() - 1; i++)
    {
        if (path1[i + 1] != path2[i + 1])
            return path1[i];
    }
    return NULL;
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