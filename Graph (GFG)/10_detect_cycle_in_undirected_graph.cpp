// Time Complexity => O(V+E)
#include <bits/stdc++.h>
using namespace std;

bool DFSutil(vector<int> adj[], int s, bool visited[], int parent)
{
    visited[s] = true;

    for (int u : adj[s])
    {
        if (visited[u] == false)
        {
            if (DFSutil(adj, u, visited, s) == true)
                return true;
        }
        else if (u != parent)
            return true;
    }
    return false;
}

bool DFS(vector<int> adj[], int V)
{
    bool visited[V] = {false};

    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
            if (DFSutil(adj, i, visited, -1) == true)
                return true;
    }
    return false;
}

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

/*
        0       4
       / \     / \
      1   2   5---6
       \ /
        3
*/

int main()
{
    int V = 7;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 1, 3);
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 6);
    addEdge(adj, 4, 6);

    cout << "Detection of cycle in graph : " << endl;
    if (DFS(adj, V) == true)
        cout << "Present";
    else
        cout << "Absent";

    return 0;
}