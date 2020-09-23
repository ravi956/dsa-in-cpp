//This is a better solution as compared to naive solution but it can be optimized
//It requires three traversals of the array which can be optimized to one traversal (see next program)
//For Naive [Time complexity = O(n*n), Space complexity = O(1)]
//For this solution [Time complexity = O(n) , Space complexity = O(n)]
#include <bits/stdc++.h>
using namespace std;

vector<int> prevSmallestElement(int arr[], int n)
{
    vector<int> res;
    stack<int> s;
    res.push_back(-1);
    s.push(0);
    for (int i = 1; i < n; i++)
    {
        while (s.empty() == false && arr[s.top()] >= arr[i])
            s.pop();

        int prevSmallest = s.empty() ? -1 : s.top();
        res.push_back(prevSmallest);
        s.push(i);
    }
    return res;
}

vector<int> nextSmallestElement(int arr[], int n)
{
    vector<int> res;
    stack<int> s;
    res.push_back(n);
    s.push(n - 1);
    for (int i = n - 2; i >= 0; i--)
    {
        while (s.empty() == false && arr[s.top()] >= arr[i])
            s.pop();

        int nextSmallest = s.empty() ? n : s.top();
        res.push_back(nextSmallest);
        s.push(i);
    }
    reverse(res.begin(), res.end());
    return res;
}

int largestArea(int arr[], int n)
{
    vector<int> preSmall = prevSmallestElement(arr, n);
    vector<int> nexSmall = nextSmallestElement(arr, n);
    for (int val : preSmall)
        cout << val << " ";
    cout << endl;
    for (int val : nexSmall)
        cout << val << " ";
    cout << endl;
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        curr += (i - preSmall[i] - 1) * arr[i];
        curr += (nexSmall[i] - i - 1) * arr[i];
        result = max(result, curr);
    }
    return result;
}

int main()
{
    int n;
    cout << "Enter no. of elements : ";
    cin >> n;
    int arr[n];
    cout << "Enter elements :\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Largest Area : ";
    cout << largestArea(arr, n);
    return 0;
}