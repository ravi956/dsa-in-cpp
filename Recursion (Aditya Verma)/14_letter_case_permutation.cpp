//In the program you have to return a vector of strings of different combinations of case_change among letters of a string
//for example : input->["a1B2"] , output->["a1b2","A1b2","a1B2","A1B2"]

#include <bits/stdc++.h>
using namespace std;

void solve(string output, string input, vector<string> &v) //Application of Input-Output Method (Recursive Tree)
{
    if (input.length() == 0) //Base Condition
    {
        v.push_back(output);
        return;
    }
    else if (isdigit(input[0]))
    {
        string op = output + input[0];
        input.erase(input.begin());
        solve(op, input, v);
    }
    else
    {
        string op1 = output;
        string op2 = output;
        op1.push_back(tolower(input[0]));
        op2.push_back(toupper(input[0]));
        input.erase(input.begin());
        solve(op1, input, v);
        solve(op2, input, v);
    }
}

int main()
{
    string input;
    string output = "";
    vector<string> permutations;
    cout << "Enter the string : ";
    cin >> input;
    solve(output, input, permutations); //Recursive function to return all the permutation of string with case change
    for (string s : permutations)
        cout << s << " ";
    return 0;
}