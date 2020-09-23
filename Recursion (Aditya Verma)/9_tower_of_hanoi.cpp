//The problem is to place all the n plates from tower A to tower C with the help of auxiliary tower B
//and not placing a large plate over small plate and trasferring one plate at a time

#include <iostream>
using namespace std;

void toh(int n, char A, char C, char B, int &count) //Hypothesis, that it will transfer n plates from A to C using B as auxiliary
{
    if (n == 0) //Base Case
    {
        return;
    }
    count++;
    toh(n - 1, A, B, C, count);                                         //Hypothesis, move upper n-1 plates from A to B using C as auxiliary
    cout << "Move plate " << n << " from " << A << " to " << C << "\n"; //Induction, move the last plate from A to C
    toh(n - 1, B, C, A, count);                                         //Hypothesis, moving the upper n-1 plates from B to C using A as auxiliary
}

int main()
{
    int n;
    int count = 0;
    cout << "Enter value of n :";
    cin >> n;
    toh(n, 'A', 'C', 'B', count); //Recursive function to transfer plates in the given condition
    cout << "Total no. of steps : " << count;
    return 0;
}