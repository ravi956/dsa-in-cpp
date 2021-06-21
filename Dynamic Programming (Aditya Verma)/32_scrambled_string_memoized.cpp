// Problem Statement : https://leetcode.com/problems/scramble-string/

#include<bits/stdc++.h>
using namespace std;

unordered_map<string, bool> mp;

bool isScrambled(string a, string b)
{
    if (a.length() != b.length())
        return false;
    if (a == b)
        return true;
    if (a.length() == 1)
        return false;

    string key = a + " " + b;

    if (mp.find(key) != mp.end())
        return mp[key];

    for (int k = 1; k < a.length(); k++)
    {
        if (isScrambled(a.substr(0, k), b.substr(b.length() - k)) && isScrambled(a.substr(k), b.substr(0, b.length() - k)))
            return mp[key] = true;
        if (isScrambled(a.substr(0, k), b.substr(0, k)) && isScrambled(a.substr(k), b.substr(k)))
            return mp[key] = true;
    }
    return mp[key] = false;
}

int main()
{
    string a, b;
    cout << "Enter first string : ";
    cin >> a;
    cout << "Enter second string : ";
    cin >> b;

    mp.clear();
    cout << isScrambled(a, b);
    return 0;
}