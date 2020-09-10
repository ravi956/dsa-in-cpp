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
void printList(Node *head);
void solveNaive(Node *head)
{
    vector<int> v;
    for (Node *curr = head; curr != NULL; curr = curr->next)
        v.push_back(curr->key);
    for (Node *curr = head; curr != NULL; curr = curr->next)
    {
        curr->key = v.back();
        v.pop_back();
    }
    cout << "New Linked list is :\n";
    printList(head);
}
//For reversing the linked list in actual originally use return type of Node* to return and update the head
//Otherwise the changes made in the function remains limited to it
//Or you can also use concept of double pointer in order to achieve it without returning head or anything from function
void solveEffective(Node *head)
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
    cout << "Reversed Linked list is :\n";
    printList(prev);
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
    solveEffective(head);
    // printList(head);
    return 0;
}