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

//Time complexity = O(m+n) [m->length of list1 and n->length of list2]
//Space complexity = O(1)
Node *mergeList(Node *a, Node *b)
{
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;
    Node *head = NULL, *tail = NULL;
    if (a->key <= b->key)
    {
        head = tail = a;
        a = a->next;
    }
    else
    {
        head = tail = b;
        b = b->next;
    }
    while (a != NULL && b != NULL)
    {
        if (a->key <= b->key)
        {
            tail->next = a;
            tail = a;
            a = a->next;
        }
        else
        {
            tail->next = b;
            tail = b;
            b = b->next;
        }
    }
    if (a == NULL)
        tail->next = b;
    else
        tail->next = a;
    return head;
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
    Node *head1 = NULL;
    Node *head2 = NULL;
    int n1;
    cout << "Enter no. of elements in linked list 1:";
    cin >> n1;
    cout << "Enter elements :\n";
    for (int i = 0; i < n1; i++)
    {
        int key;
        cin >> key;
        head1 = insertEnd(head1, key);
    }
    int n2;
    cout << "Enter no. of elements in linked list 2:";
    cin >> n2;
    cout << "Enter elements :\n";
    for (int i = 0; i < n2; i++)
    {
        int key;
        cin >> key;
        head2 = insertEnd(head2, key);
    }
    Node *head = mergeList(head1, head2);
    printList(head);
    return 0;
}