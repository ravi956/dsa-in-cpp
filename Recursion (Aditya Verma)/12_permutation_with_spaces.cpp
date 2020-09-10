//In the program you have to print different combinations of spacing between two letters of a string
//for example : input->["abc"] , output->["a bc", "a b c", "ab c", "abc"]

#include <iostream>
using namespace std;

void solve(string output, string input) //Application of Input-Output Method (Recursive Tree)
{
    if (input.length() == 0) //Base Condition
    {
        cout << output << endl;
        return;
    }
    string op1 = output + input[0];
    string op2 = output + " " + input[0];
    input.erase(input.begin());
    solve(op1, input);
    solve(op2, input);
}

int main()
{
    string input;
    cout << "Enter the string : ";
    cin >> input;
    string output = "";
    output += input[0];
    input.erase(input.begin());
    solve(output, input); //Recursive function to print all the permutation of string with spaces
    return 0;
}