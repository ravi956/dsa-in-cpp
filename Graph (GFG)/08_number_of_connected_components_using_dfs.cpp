#include <bits/stdc++.h>
using namespace std;

void DFSutil(vector<int> adj[], int s, bool visited[])
{
    visited[s] = true;
    // cout << s << " ";

    for (int u : adj[s])
    {
        if (visited[u] == false)
            DFSutil(adj, u, visited);
    }
}

int DFS(vector<int> adj[], int V)
{
    int connected_comp = 0;
    bool visited[V] = {false};

    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
        {
            DFSutil(adj, i, visited);
            connected_comp++;
        }
    }
    return connected_comp;
}

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

/*
        0       4       7
       / \     / \      |
      1   2   5---6     8
       \ /
        3
*/

int main()
{
    int V = 9;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 1, 3);
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 6);
    addEdge(adj, 4, 6);
    addEdge(adj, 7, 8);

    cout << "Connected Components : " << endl;
    cout << DFS(adj, V);

    return 0;
}