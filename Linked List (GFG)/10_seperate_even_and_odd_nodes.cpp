//Segregate or seperate even and odd nodes of a singly linked list maintaining their relative order
//and all the even nodes comes before the odd nodes
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

Node *segregate(Node *head)
{
    Node *eStart = NULL, *eEnd = NULL, *oStart = NULL, *oEnd = NULL;
    for (Node *curr = head; curr != NULL; curr = curr->next)
    {
        int x = curr->key;
        if (x % 2 == 0)
        {
            if (eStart == NULL)
            {
                eStart = curr;
                eEnd = curr;
            }
            else
            {
                eEnd->next = curr;
                eEnd = eEnd->next;
            }
        }
        else
        {
            if (oStart == NULL)
            {
                oStart = curr;
                oEnd = curr;
            }
            else
            {
                oEnd->next = curr;
                oEnd = oEnd->next;
            }
        }
    }

    if (oStart == NULL || eStart == NULL)
        return head;
    eEnd->next = oStart;
    oEnd->next = NULL;
    return eStart;
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
    head = segregate(head);
    printList(head);
    return 0;
}