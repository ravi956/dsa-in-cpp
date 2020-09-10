#include<iostream>
#include<stack>
using namespace std;

void insert(stack<int> &s, int temp)
{
    if (s.size()==0)
    {
        s.push(temp);
        return;
    }
    int last = s.top();
    s.pop();
    insert(s, temp);
    s.push(last);
}

void reverse(stack<int> &s) //Hypothesis is that it will reverse the whole stack
{
    if (s.size()==1)        //Base Case
        return;
    int temp = s.top();
    s.pop();                //Induction
    reverse(s);             //Hypothesis
    insert(s, temp);        //Induction, it is also a recursive function to insert the popped element at last
}

int main()
{
    int n;
    cout << "***************Program to reaverse stack using Recursion******************\n";
    cout << "Enter no. of element in the stack : ";
    cin >> n;
    stack<int> s;
    cout << "Enter the elements : ";
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        s.push(temp);
    }
    reverse(s); //Recursive function to reverse a stack
    cout << "Elements after Reversing are : ";
    while (s.empty() == false)
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}