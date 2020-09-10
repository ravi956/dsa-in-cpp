//In the program you have to print different combinations of case_change among letters of a string
//for example : input->["ab"] , output->["ab","Ab","aB","AB"]

#include <bits/stdc++.h>
using namespace std;

void solve(string output, string input) //Application of Input-Output Method (Recursive Tree)
{
    if (input.length() == 0) //Base Condition
    {
        cout << output << " ";
        return;
    }
    string op1 = output + input[0];
    char temp = toupper(input[0]);
    string op2 = output + temp;
    input.erase(input.begin());
    solve(op1, input);
    solve(op2, input);
}

int main()
{
    string input;
    string output = "";
    cout << "Enter the string : ";
    cin >> input;
    solve(output, input); //Recursive function to print all the permutation of string with case change
    return 0;
}