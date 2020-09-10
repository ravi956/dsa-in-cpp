#include<bits/stdc++.h>
using namespace std;

int solve(int arr[],int n, int sum)
{
    unordered_map<int, int> m;
    int pre_sum = 0, res = 0;
    for(int i=0; i<n; i++)
    {
        pre_sum += arr[i];
        if(pre_sum==sum)
        res = i+1;
        if(m.find(pre_sum-sum)!=m.end())
        res = max(res,i-(m[pre_sum-sum]));
        if(m.find(pre_sum-sum)==m.end())
        m.insert({pre_sum,i});
    }
    return res;
}

int main()
{
    int arr[]={8,3,1,5,-6,6,2,2};
    cout<<solve(arr,sizeof(arr)/sizeof(int),4);
    return 0;
}