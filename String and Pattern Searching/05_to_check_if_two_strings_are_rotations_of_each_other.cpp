//To check if strings are rotations of each other

#include <bits/stdc++.h>
using namespace std;

// bool isRotation(string &s1, string &s2)
// {
//     int n1=s1.length();
//     int n2=s2.length();
//     if(n1!=n2)
//     return false;
//     int i=0;
//     int j=s2.find(s1[0]);
//     if(j==string::npos)
//     return false;
//     while(i<n1)
//     {
//         if(s1[i]!=s2[j])
//         return false;
//         j=(j+1)%n2;
//         i++;
//     }
//     return true;
// }

bool isRotation(string &s1, string &s2)
{
    if (s1.length() != s2.length())
        return false;
    return ((s1 + s1).find(s2) != string::npos);
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    if (isRotation(s1, s2) || isRotation(s2, s1))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
