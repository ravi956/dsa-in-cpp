#include <bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
    Node *next;
    Node(char x)
    {
        data = x;
        next = NULL;
    }
};
// Write your function below //

Node *reverse(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    while (curr != NULL)
    {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool isPalindrome(Node *head)
{
    if (head == NULL)
        return true;
    Node *slow_p = head, *fast_p = head;
    while (fast_p->next != NULL && fast_p->next->next != NULL)
    {
        fast_p = fast_p->next->next;
        slow_p = slow_p->next;
    }
    Node *rev = reverse(slow_p->next);
    Node *curr = head;
    while (rev != NULL)
    {
        if (rev->data != curr->data)
            return false;
        rev = rev->next;
        curr = curr->next;
    }
    return true;
}

// Write your function above //

Node *insertBegin(Node *head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    return temp;
}

Node *insertEnd(Node *head, int data)
{
    if (head == NULL)
        return new Node(data);
    Node *curr = head;
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = new Node(data);
    return head;
}

void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
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
        char data;
        cin >> data;
        head = insertEnd(head, data);
    }
    cout << isPalindrome(head);
    return 0;
}