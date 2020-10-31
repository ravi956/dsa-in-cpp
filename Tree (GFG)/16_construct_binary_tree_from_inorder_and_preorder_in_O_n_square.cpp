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

int preIndex = 0;

//Time Complexity = O(n*n)
Node *cTree(int in[], int pre[], int is, int ie)
{
    if (is > ie)
        return NULL;

    Node *root = new Node(pre[preIndex++]);

    int inIndex;
    //This part can be implemented by using a hashTable
    //which reduces the time complexity to O(n)
    for (int i = is; i <= ie; i++)
    {
        if (in[i] == root->data)
        {
            inIndex = i;
            break;
        }
    }

    root->left = cTree(in, pre, is, inIndex - 1);
    root->right = cTree(in, pre, inIndex + 1, ie);
    return root;
}

/* Given a binary tree, print its nodes in inorder*/
void printInorder(struct Node *node)
{
    if (node == NULL)
        return;

    /* first recur on left child */
    printInorder(node->left);

    /* then print the data of node */
    cout << node->data << " ";

    /* now recur on right child */
    printInorder(node->right);
}

/* Given a binary tree, print its nodes in preorder*/
void printPreorder(struct Node *node)
{
    if (node == NULL)
        return;

    /* first print data of node */
    cout << node->data << " ";

    /* then recur on left sutree */
    printPreorder(node->left);

    /* now recur on right subtree */
    printPreorder(node->right);
}

int main()
{
    int n;
    cout << "Enter no. of nodes : ";
    cin >> n;
    int in[n], pre[n];
    cout << "Enter inorder traversal array :\n";
    for (int i = 0; i < n; i++)
        cin >> in[i];
    cout << "Enter preorder traversal array :\n";
    for (int i = 0; i < n; i++)
        cin >> pre[i];
    Node *root = cTree(in, pre, 0, n - 1);
    //For Verification of the code
    cout << endl;
    printInorder(root);
    cout << endl;
    printPreorder(root);
    return 0;
}