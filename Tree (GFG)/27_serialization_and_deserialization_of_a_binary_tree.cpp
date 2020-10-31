//Preorder Approach
//Time complexity => Theta(n)
//Space complexity => Theta(n)  for both the functions

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

const int EMPTY = -1;

void serialize(Node *root, vector<int> &arr)
{
    if (root == NULL)
    {
        arr.push_back(EMPTY);
        return;
    }
    arr.push_back(root->data);
    serialize(root->left, arr);
    serialize(root->right, arr);
}

Node *deSerialize(vector<int> &arr, int &index)
{
    if (index == arr.size())
        return NULL;

    int val = arr[index];
    index++;
    if (val == EMPTY)
        return NULL;

    Node *root = new Node(val);
    root->left = deSerialize(arr, index);
    root->right = deSerialize(arr, index);

    return root;
}

/*
Example for serialization
                    10
                   /  \
                  2    8
                 / \   /
                1   6 9
*/

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
    Node *root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->right->left = new Node(9);

    //serialization
    vector<int> sArray;
    serialize(root, sArray);
    for (int val : sArray)
        cout << val << " ";
    cout << endl;

    //deserialization
    int index = 0;
    Node *newRoot = deSerialize(sArray, index);
    printPreorder(newRoot);
    return 0;
}