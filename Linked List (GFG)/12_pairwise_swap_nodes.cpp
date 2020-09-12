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

//This method simply swap the data stored in the nodes without modifying any links which can be costly if data is large
//Time complexity = O(n)
//Space complexity = O(1)
void solveNaive(Node *head)
{
    Node *curr = head;
    while (curr != NULL && curr->next != NULL)
    {
        swap(curr->key, curr->next->key);
        curr = curr->next->next;
    }
}

//This is the better method as compared to the above which modifies the link instead of modifying the data of nodes
//Time complexity = O(n)
//Space complexity = O(1)
Node *pairSwap(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *curr = head->next->next;
    Node *prev = head;
    head = head->next;
    head->next = prev;
    while (curr != NULL && curr->next != NULL)
    {
        prev->next = curr->next;
        prev = curr;
        Node *next = curr->next->next;
        curr->next->next = curr;
        curr = next;
    }
    prev->next = curr;
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
    head = pairSwap(head);
    // solveNaive(head);
    cout << "After Swapping : \n";
    printList(head);
    return 0;
}