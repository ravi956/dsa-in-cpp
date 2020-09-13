//In this problem we have to clone a linked list which has next pointers and also random pointer
//pointing to a random node of the linked list
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *random;
    Node(int x)
    {
        data = x;
        next = NULL;
        random = NULL;
    }
};
// Write your function below //

//Time complexity = O(n)
//Space complexity = O(n)
Node *naiveClone(Node *head)
{
    unordered_map<Node *, Node *> mp;
    Node *curr = NULL;
    for (curr = head; curr != NULL; curr = curr->next)
        mp[curr] = new Node(curr->data);
    for (curr = head; curr != NULL; curr = curr->next)
    {
        mp[curr]->next = mp[curr->next];
        mp[curr]->random = mp[curr->random];
    }
    return mp[head];
}

Node *trickyClone(Node *head)
{
    //Placing the dummy nodes bw the nodes of the original linked list
    for (Node *curr = head; curr != NULL;)
    {
        Node *next = curr->next;
        curr->next = new Node(curr->data);
        curr->next->next = next;
        curr = next;
    }

    //Assigning the random pointers their address to point
    for (Node *curr = head; curr != NULL; curr = curr->next->next)
        curr->next->random = (curr->random != NULL) ? curr->random->next : NULL;

    //Final step : deleting the dummy nodes from the original linked list and creating the final clone linked list
    Node *curr = NULL;
    Node *cloneHead = head->next;
    for (curr = head; curr->next->next != NULL; curr = curr->next)
    {
        Node *dummy = curr->next;
        curr->next = dummy->next;
        dummy->next = dummy->next->next;
    }
    curr->next = NULL;
    return cloneHead;
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
    cout << "Please enter atleast 3 nodes for testing the clone function ....\n";
    cout << "Enter no. of elements in linked list :";
    cin >> n;
    cout << "Enter elements :\n";
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        head = insertEnd(head, data);
    }
    //For setting the randoms pointers for testing purpose of the clone function
    Node *curr = head;
    while (curr != NULL && curr->next->next != NULL)
    {
        curr->random = curr->next->next;
        curr = curr->next;
    }
    curr->random = head;
    curr->next->random = head->next;
    // Node *cloneHead = naiveClone(head);
    Node *cloneHead = trickyClone(head);
    printList(cloneHead);
    return 0;
}