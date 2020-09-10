#include <iostream>
using namespace std;

void print(int n)
{
    if (n == 1) //Base Case
    {
        cout << 1 << " ";
        return;
    }
    cout << n << " "; //Induction
    print(n - 1);     //Hypothesis is print(n) function will print n to 1 OR print(n-1) will print n-1 to 1
}

int main()
{
    int n;
    cout << "****************Program to print n to 1 using Recursion**************************\n";
    cout << "Enter the value of n : ";
    cin >> n;
    cout << "Numbers are : ";
    print(n); //Function to print n to 1
    return 0;
}