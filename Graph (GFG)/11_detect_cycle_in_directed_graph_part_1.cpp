// Time Complexity => O(V+E)
#include <bits/stdc++.h>
using namespace std;

bool DFSutil(vector<int> adj[], int s, bool visited[], bool recStack[])
{
    visited[s] = true;
    recStack[s] = true;

    for (int u : adj[s])
    {
        if (visited[u] == false && DFSutil(adj, u, visited, recStack) == true)
        {
            return true;
        }
        else if (recStack[u] == true)
            return true;
    }
    recStack[s] = false;
    return false;
}

bool DFS(vector<int> adj[], int V)
{
    bool visited[V] = {false};
    bool recStack[V] = {false};

    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
            if (DFSutil(adj, i, visited, recStack) == true)
                return true;
    }
    return false;
}

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    // adj[v].push_back(u);
}

/*
        0----->1<------2------->3------->4------->5
                                ^                 |
                                |_________________|
*/

int main()
{
    int V = 6;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 2, 1);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 3);

    cout << "Detection of cycle in graph : " << endl;
    if (DFS(adj, V))
        cout << "Cycle found";
    else
        cout << "No cycle found";

    return 0;
}