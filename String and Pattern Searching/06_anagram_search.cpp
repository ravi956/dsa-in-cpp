//Anagram Search : to search if there is any Anagram of pattern string in the text string
//Time Complexity = O(m+(n-m)*CHAR) = O(n)  [where m=pat.length(), n=txt.length()]
//Space Complexity = O(CHAR)

#include <bits/stdc++.h>
using namespace std;
#define CHAR 256

bool areSame(int *CT, int *CP)
{
    for (int i = 0; i < CHAR; i++)
        if (CT[i] != CP[i])
            return false;
    return true;
}

bool isPresent(string &txt, string &pat)
{
    int CT[CHAR] = {0}, CP[CHAR] = {0};
    for (int i = 0; i < pat.length(); i++)
    {
        CT[txt[i]]++;
        CP[pat[i]]++;
    }
    for (int i = pat.length(); i < txt.length(); i++)
    {
        if (areSame(CT, CP))
            return true;
        CT[txt[i - pat.length()]]--;
        CT[txt[i]]++;
    }
    return false;
}

int main()
{
    string txt, pat;
    cin >> txt >> pat;
    if (isPresent(txt, pat))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
