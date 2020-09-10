#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node *next;
    Node *prev;
    Node(int x)
    {
        key = x;
        next = prev = NULL;
    }
};

Node *insertBegin(Node *head, int key)
{
    if (head == NULL)
        return new Node(key);
    Node *temp = new Node(key);
    temp->next = head;
    head->prev = temp;
    return temp;
}

Node *insertEnd(Node *head, int key)
{
    if (head == NULL)
        return new Node(key);
    Node *curr = head;
    Node *temp = new Node(key);
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = temp;
    temp->prev = curr;
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
    head = insertBegin(head, 10);
    head = insertBegin(head, 20);
    head = insertBegin(head, 30);
    head = insertEnd(head, 50);
    printList(head);
    return 0;
}