#include <iostream>
#include <unordered_set>
using namespace std;

void powerSet(string output, string input, unordered_set<string> &s) //Application of Input-Output Method (Recursive Tree)
{
    if (input.length() == 0) //Base Condition
    {
        s.insert(output);
        return;
    }
    string op1 = output;
    string op2 = output + input[0];
    input.erase(input.begin());
    powerSet(op1, input, s);
    powerSet(op2, input, s);
}

int main()
{
    string input;
    cout << "Enter the string : ";
    cin >> input;
    string output = "";
    unordered_set<string> s;
    powerSet(output, input, s); //Recursive function to print all the unique subsets of input string
    cout << "Unique subsets are : ";
    for (auto itr : s)
        cout << itr << " ";
    return 0;
}