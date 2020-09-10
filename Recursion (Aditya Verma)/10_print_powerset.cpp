#include <iostream>
using namespace std;

void powerSet(string output, string input) //Application of Input-Output Method (Recursive Tree)
{
    if (input.length() == 0) //Base Condition
    {
        cout << output << " ";
        return;
    }
    string op1 = output;
    string op2 = output + input[0];
    input.erase(input.begin());
    powerSet(op1, input);
    powerSet(op2, input);
}

int main()
{
    string input;
    cout << "Enter the string : ";
    cin >> input;
    string output = "";
    powerSet(output, input); //Recursive function to print all the subsets of input string
    return 0;
}