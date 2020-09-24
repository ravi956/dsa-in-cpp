//Input -> is a number n
//Problem Statement -> generate strings of balanced parenthesis having n opening brackets and n closing brackest
//For example : [Input : n=1] -> [Output : ()] , [Input : n=2] -> [Output : (()),()()],
//[Input : n=3] -> [Output : ((())),(()()),(())(),()(()),()()()]
//Output -> return these outputs in a vector of strings

#include <bits/stdc++.h>
using namespace std;

void genBalPar(int ob, int cb, string output, vector<string> &res)
{
    if (ob == 0 && cb == 0) //Base case
    {
        res.push_back(output);
        return;
    }

    if (ob != 0)
    {
        genBalPar(ob - 1, cb, output + '(', res);
    }
    if (ob < cb)
    {
        genBalPar(ob, cb - 1, output + ')', res);
    }
}

int main()
{
    int n;
    cout << "Enter n : ";
    cin >> n;
    vector<string> res;
    int ob = n; //no. of openning brackets
    int cb = n; //no. of closing brackets
    string output = "";
    genBalPar(ob, cb, output, res); //Recursive function to generate balanced parenthesis;
    cout << "Balanced parenthesis : \n";
    for (string s : res)
        cout << s << " ";
    return 0;
}