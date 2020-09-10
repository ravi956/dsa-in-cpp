//This program is same as sorting an array
#include <iostream>
#include <stack>
using namespace std;

void insert(stack<int> &s, int top_element) //Hypothesis
{
    if (s.empty() == true || s.top() <= top_element) //Base Case
    {
        s.push(top_element);
        return;
    }
    int temp = s.top();
    s.pop();                //Induction
    insert(s, top_element); //Hypothesis
    s.push(temp);           //Induction
}

void sort(stack<int> &s) //Hypothesis that it will sort all elements of stack
{
    if (s.size() == 1) //Base case -> stack of one element is sorted in itself
        return;
    int top_element = s.top();
    s.pop();
    sort(s);                //this will sort all elements in the stack excluding the last one which is popped out and stored in the top_element
    insert(s, top_element); //Induction this is also a recursive func which will insert the top_element at its position in the sorted stack
}

int main()
{
    int n;
    cout << "***************Program to sort stack using Recursion******************\n";
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
    sort(s); //Recursive function to sort stack
    cout << "Elements after Sorting are : ";
    while (s.empty() == false)
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}