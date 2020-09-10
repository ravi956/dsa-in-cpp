#include <iostream>
using namespace std;

void print(int n)
{
    if (n == 1) //Base Case
    {
        cout << 1 << " ";
        return;
    }
    print(n - 1);     //Hypothesis is print(n) function will print 1 to n OR print(n-1) will print 1 to n-1
    cout << n << " "; //Induction
}

int main()
{
    int n;
    cout << "****************Program to print 1 to n using Recursion**************************\n";
    cout << "Enter the value of n : ";
    cin >> n;
    cout << "Numbers are : ";
    print(n); //Function to print 1 to n
    return 0;
}