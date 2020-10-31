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

//Time Complexity = O(n)
Node *cTree(int in[], int pre[], int is, int ie, unordered_map<int, int> inTable)
{
    if (is > ie)
        return NULL;

    Node *root = new Node(pre[preIndex++]);

    int inIndex = inTable[root->data];

    root->left = cTree(in, pre, is, inIndex - 1, inTable);
    root->right = cTree(in, pre, inIndex + 1, ie, inTable);
    return root;
}

//Below two methods are only for the verification of the code

void printInorder(struct Node *node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

void printPreorder(struct Node *node)
{
    if (node == NULL)
        return;
    cout << node->data << " ";
    printPreorder(node->left);
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

    //Creating HashTable for inorder traversal array
    unordered_map<int, int> inTable;
    for (int i = 0; i < n; i++)
    {
        inTable[in[i]] = i;
    }

    Node *root = cTree(in, pre, 0, n - 1, inTable);
    //For Verification of the code
    cout << endl;
    printInorder(root);
    cout << endl;
    printPreorder(root);
    return 0;
}