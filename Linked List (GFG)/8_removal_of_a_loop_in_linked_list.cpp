//Removal of the loop if it exists using Floyd's Cycle Detection
//This program can also be used with some modification to find :
//(1) Length of the loop         --> This is the variation of loop detection problem
//(2) The first node of the loop --> This is the variation of loop removal problem
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

void removeLoop(Node *head)
{
    //This part is for Detection of the loop
    Node *slow_p = head, *fast_p = head;
    while (fast_p != NULL && fast_p->next != NULL)
    {
        fast_p = fast_p->next->next;
        slow_p = slow_p->next;
        if (slow_p == fast_p) //Here (slow_p == fast_p) will give the first meeting point
            break;
    }

    if (slow_p != fast_p)
        return;

    //To calculate the length of the loop , fix one of the pointers after reaching the first meeting point
    //and keep incrementing the other pointer untill you reach that fixed pointer again
    //During incrementing the pointer (increment the count which counts the nodes in the loop)
    //(This is done because after reaching the first meeting point you are still in the loop)

    //This part is for removal of the loop
    slow_p = head;
    while (slow_p->next != fast_p->next) //(slow_p == fast_p) will give the first node of the loop
    {
        slow_p = slow_p->next;
        fast_p = fast_p->next;
    }
    fast_p->next = NULL;
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
    //to make a loop in linked list
    char ch;
    cout << "Want to add a node to make a loop for testing purpose (y/n) : ";
    cin >> ch;
    if (ch == 'y')
    {
        Node *last = new Node(0);
        Node *ptr = head;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = last;
        last->next = head->next;
    }
    removeLoop(head);
    printList(head);
    return 0;
}