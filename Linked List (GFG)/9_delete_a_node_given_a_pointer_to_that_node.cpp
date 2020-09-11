//Assume the node to be deleted is not the last node
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    Node *next;
    Node(int x)
    {
        key = x;
        next = NULL;
    }
};
// Write your function below //

void deleteNode(Node *ptr) //ptr is the pointer to the node to be deleted
{
    Node *temp = ptr->next;
    ptr->key = temp->key;
    ptr->next = temp->next;
    delete (temp);
}

// Write your function above //

Node *insertBegin(Node *head, int key)
{
    Node *temp = new Node(key);
    temp->next = head;
    return temp;
}

Node *insertEnd(Node *head, int key)
{
    if (head == NULL)
        return new Node(key);
    Node *curr = head;
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = new Node(key);
    return head;
}

void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->key << " ";
        head = head->next;
    }
}

int main()
{
    Node *head = NULL;
    int n;
    cout << "Enter no. of elements in linked list :";
    cin >> n;
    cout << "Enter elements :\n";
    for (int i = 0; i < n; i++)
    {
        int key;
        cin >> key;
        head = insertEnd(head, key);
    }
    Node *delNode = head->next;
    deleteNode(delNode);
    printList(head);
    return 0;
}