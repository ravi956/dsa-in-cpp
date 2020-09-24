//Input -> n=3
//Output -> 111, 110, 101

#include <bits/stdc++.h>
using namespace std;

void nbit(int ones, int zeros, int n, string output, vector<string> &res)
{
    if (n == 0) //Base case
    {
        res.push_back(output);
        return;
    }

    nbit(ones + 1, zeros, n - 1, output + '1', res);
    if (ones > zeros)
        nbit(ones, zeros + 1, n - 1, output + '0', res);
}

int main()
{
    int n;
    cout << "Enter n : ";
    cin >> n;
    vector<string> res;
    nbit(0, 0, n, "", res); //Recursive function to generate n bit binary no. having more 1's than 0's in any prefix;
    cout << "Required Binary Numbers : \n";
    for (string s : res)
        cout << s << " ";
    return 0;
}