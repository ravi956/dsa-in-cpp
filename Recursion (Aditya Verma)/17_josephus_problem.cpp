// #include <bits/stdc++.h>
// using namespace std;

// int solve(int k, int index, vector<int> &currSurvivors)
// {
//     if (currSurvivors.size() == 1) //Base case
//         return currSurvivors[0];

//     index = (index + k) % currSurvivors.size();
//     currSurvivors.erase(currSurvivors.begin() + index);
//     return solve(k, index % currSurvivors.size(), currSurvivors);
// }

// int main()
// {
//     int n, k;
//     cout << "Enter value of n and k :";
//     cin >> n >> k;
//     vector<int> currSurvivors;
//     for (int i = 0; i < n; i++)
//         currSurvivors.push_back(i + 1);
//     k--;
//     cout << "Survivor's Position : ";
//     cout << solve(k, 0, currSurvivors);
//     return 0;
// }

//Method 2

#include <bits/stdc++.h>
using namespace std;

int josephus(int n, int k);

int main()
{

    int n, k;
    cout << "Enter value of n and k :";
    cin >> n >> k;
    cout << "Survivor's Position : ";
    cout << josephus(n, k) << endl;
    return 0;
} // } Driver Code Ends

/*You are required to complete this method */
int josephus(int n, int k)
{
    if (n == 1)
    {
        return 1;
    }
    return (josephus(n - 1, k) + k - 1) % n + 1;
}
