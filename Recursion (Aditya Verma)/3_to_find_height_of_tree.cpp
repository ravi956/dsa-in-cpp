#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node *insert(Node *r, int value) //Function to insert node in a tree in order to create tree
{
    if (r == NULL)
    {
        r = (Node *)malloc(sizeof(Node));
        r->data = value;
        r->left = NULL;
        r->right = NULL;
    }
    else if (value < r->data)
        r->left = insert(r->left, value);
    else
        r->right = insert(r->right, value);
    return r;
}

//Recursive Function height() to return the height of the tree
int height(Node *r) //Hypothesis that height(Node *r) will return height of the tree with root node r
{
    if (r == NULL) //Base case
        return 0;
    return 1 + max(height(r->left), height(r->right)); //Induction
}

int main()
{
    Node *root = NULL;
    int n;
    cout << "******************Creation of Tree***********************\n";
    cout << "Enter Number of elements in Tree : ";
    cin >> n;
    cout << "Enter elements : \n";
    while (n--)
    {
        int element;
        cin >> element;
        root = insert(root, element); //to insert node in a tree
    }
    int h = height(root); //to calculate height of the tree
    cout << "Height of the tree is : " << h;
    return 0;
}