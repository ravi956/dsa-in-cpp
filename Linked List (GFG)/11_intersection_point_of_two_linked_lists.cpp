//To find the intersection of point of two linked lists
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

//Time complexity = O(m+n) [where m is the length of first list and n is the length of second list]
//Space complexity = O(m)
Node *naiveMethod(Node *head1, Node *head2)
{
    unordered_set<Node *> s;
    for (Node *curr = head1; curr != NULL; curr = curr->next)
        s.insert(curr);
    Node *curr = NULL;
    for (curr = head2; curr != NULL; curr = curr->next)
    {
        if (s.find(curr) != s.end())
            break;
    }
    return curr;
}

//Time complexity = O(m+n)
//Space complexity = O(1)
Node *intersectPoint(Node *head1, Node *head2)
{
    int c1 = 0, c2 = 0; //Here c1 = length of linked list1 and c2 = length of linked list2
    for (Node *curr = head1; curr != NULL; curr = curr->next)
        c1++;
    for (Node *curr = head2; curr != NULL; curr = curr->next)
        c2++;
    int shift = abs(c1 - c2);
    //These many shifts are to be made in the longest linked list in order to reach the intersection point at same time
    Node *curr = NULL;
    if (c1 > c2)
    {
        curr = head1;
        while (shift--)
            curr = curr->next;
        Node *ptr = head2;
        while (curr != ptr)
        {
            curr = curr->next;
            ptr = ptr->next;
        }
    }
    else
    {
        curr = head2;
        while (shift--)
            curr = curr->next;
        Node *ptr = head1;
        while (curr != ptr)
        {
            curr = curr->next;
            ptr = ptr->next;
        }
    }
    return curr;
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
    int t = 1;
    while (t <= 2)
    {
        int n;
        if (t == 1)
            cout << "Please make first linked list of atleast size 3 ......\n";
        cout << "Enter no. of elements in linked list " << t << " :";
        cin >> n;
        cout << "Enter elements :\n";
        for (int i = 0; i < n; i++)
        {
            int key;
            cin >> key;
            if (t == 1)
                head1 = insertEnd(head1, key);
            else
                head2 = insertEnd(head2, key);
        }
        //For testing purpose of the function , I am going to add the 3rd node of the linked list1 as the next node of the
        //last node of linked list2 (so that intersection point can exist)
        if (t == 2)
        {
            Node *ptr = head2;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = head1->next->next;
        }
        t++;
    }

    cout << "Linked list 2 after modification for testing purpose will look like : \n";
    printList(head2);
    Node *intersectingNode = intersectPoint(head1, head2);
    cout << "\nIntersecting Node => " << intersectingNode->key;
    return 0;
}