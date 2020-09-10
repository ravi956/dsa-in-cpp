#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int> &s, int k)    //Hypothesis
{
    if (k==1)                       //Base Case
    {
        s.pop();
        return;
    }
    int temp = s.top();
    s.pop();                        //Induction
    solve(s, k-1);                  //Hypothesis
    s.push(temp);                   //Induction
}

void delMid(stack<int> &s, int size)  //Simple Function to delete middle element which calls the main recursive func to do so
{
    if (s.size()==0)
        return;
    int k= size/2+1;
    solve(s, k);                      //Recursive function to delete the middle element of stack
}

int main()
{
    int n;
    cout << "***************Program to delete middle element from stack using Recursion******************\n";
    //Here middle element of stack is (stack.size()/2)+1 i.e (n/2)+1
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
    delMid(s, n); //Function to delete middle element of stack
    cout << "Elements after Deleting middle element are : ";
    while (s.empty() == false)
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}