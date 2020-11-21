#include <bits/stdc++.h>
using namespace std;

struct Triplet
{
    int val, aPos, vPos; // aPos->position of array, vPos->pos of value in array
    Triplet(int v, int ap, int vp)
    {
        val = v;
        aPos = ap;
        vPos = vp;
    }
};

struct MyComp
{
    bool operator()(Triplet &t1, Triplet &t2)
    {
        return t1.val > t2.val;
    }
};

// Time Complexity => O(nk*log(k))
// n => max no. of elements in an array
// k => no. of arrays
vector<int> mergeArr(vector<vector<int>> &v)
{
    vector<int> res;

    priority_queue<Triplet, vector<Triplet>, MyComp> pq;

    for (int i = 0; i < v.size(); i++)
    {
        Triplet t(v[i][0], i, 0);
        pq.push(t);
    }

    while (pq.empty() == false)
    {
        Triplet curr = pq.top();
        pq.pop();
        res.push_back(curr.val);
        int ap = curr.aPos;
        int vp = curr.vPos + 1;
        if (vp < v[ap].size())
        {
            Triplet next(v[ap][vp], ap, vp);
            pq.push(next);
        }
    }
    return res;
}

int main()
{
    vector<vector<int>> v;
    int k;
    cout << "Enter value of k : ";
    cin >> k;

    for (int i = 0; i < k; i++)
    {
        vector<int> temp;
        int n;
        cout << "Enter the size of the array" << i + 1 << " : ";
        cin >> n;
        cout << "Enter values of array" << i + 1 << endl;
        for (int i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            temp.push_back(num);
        }
        v.push_back(temp);
    }

    vector<int> res = mergeArr(v);
    cout << "\nMerged Array :\n";
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}