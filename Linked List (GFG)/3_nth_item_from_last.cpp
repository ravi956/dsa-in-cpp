#include <iostream>
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
void solveNaive(Node *head)
{
    int pos;
    cout << "Enter the position of element from last to be found : ";
    cin >> pos;
    Node *ptr = head;
    int length = 0;
    while (ptr != NULL)
    {
        length++;
        ptr = ptr->next;
    }
    if (length < pos)
    {
        cout << "No such position exits...\n";
        return;
    }
    ptr = head;
    while (pos < length)
    {
        ptr = ptr->next;
        pos++;
    }
    cout << ptr->key;
}

void solveEffective(Node *head)
{
    int pos;
    cout << "Enter the position of element from last to be found : ";
    cin >> pos;
    Node *second = head;
    Node *first = head;
    while (pos > 0 && first != NULL)
    {
        first = first->next;
        pos--;
    }
    if (pos != 0)
    {
        cout << "No such position exists...\n";
        return;
    }
    while (first != NULL)
    {
        first = first->next;
        second = second->next;
    }
    cout << second->key;
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