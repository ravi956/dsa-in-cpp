//Floyd's Cycle Detection
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

//Time complexity = O(n)
//Space complexity = O(1)
bool solveNaive(Node *head) //This function detects loop but destroy the linked list
{
    Node *temp = new Node(0); //Dummy Node
    Node *curr = head;
    while (curr != NULL)
    {
        if (curr->next == NULL)
            return false;
        if (curr->next == temp)
            return true;
        Node *curr_next = curr->next;
        curr->next = temp;
        curr = curr_next;
    }
    return false;
}

//Time complexity = O(n)
//Space complexity = O(n)
bool solveBetter(Node *head) //This function doesn't destroy the linked list
{
    unordered_set<Node *> s;
    for (Node *curr = head; curr != NULL; curr = curr->next)
    {
        if (s.find(curr) != s.end())
            return true;
        s.insert(curr);
    }
    return false;
}

//Time Complexity = O(n)
//Space Complexity = O(1)
//This method is called "Floyd's Cycle Detection"
bool solveEffective(Node *head) //This function doesn't make any modification to the linked list
{
    Node *slow_p = head, *fast_p = head;
    while (fast_p != NULL && fast_p->next != NULL)
    {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        if (slow_p == fast_p)
            return true;
    }
    return false;
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
    cout << solveEffective(head);
    // printList(head);
    return 0;
}