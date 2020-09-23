//You are given a string (containing only six types of characters '(',')','{','}','[',']' ) , write a function to check if
//they are balanced or not
#include <bits/stdc++.h>
using namespace std;

bool matching(char a, char b)
{
    return ((a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']'));
}

bool isBalanced(string s)
{
    stack<char> st;
    for (char c : s)
    {
        if (c == '(' || c == '{' || c == '[')
            st.push(c);
        else
        {
            if (st.empty())
                return false;
            else if (matching(st.top(), c) == false)
                st.push(c);
            else
                st.pop();
        }
    }
    return st.empty();
}

int main()
{
    string s;
    cin >> s;
    cout << isBalanced(s);
    return 0;
}