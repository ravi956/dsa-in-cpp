#include <bits/stdc++.h>
using namespace std;

/*
        0------1------3
        \     /
         \   /
          \ /
           2

*/

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(vector<int> adj[], int v)
{
    for (int i = 0; i < v; i++)
    {
        for (int x : adj[i])
            cout << x << " ";
        cout << endl;
    }
}

int main()
{
    int v = 4;
    vector<int> adj[v];

    addEdge(adj, 0, 1);
    addEdge(adj, 1, 3);
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 1);

    printGraph(adj, v);
    return 0;
}