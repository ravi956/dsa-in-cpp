// Topological Sorting (Kahn's BFS based algorithm)
// Time Complexity => O(V+E)

#include <bits/stdc++.h>
using namespace std;

void topologicalSort(vector<int> adj[], int V)
{
    vector<int> in_degree(V, 0);

    for (int u = 0; u < V; u++)
    {
        for (int v : adj[u])
        {
            in_degree[v]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (in_degree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        cout << u << " ";

        for (int v : adj[u])
        {
            if (--in_degree[v] == 0)
                q.push(v);
        }
    }
}

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

/*
        0------>2
        \     /
         \   /
     1---->3<
     |
     |_____________>4
*/

int main()
{
    int V = 5;
    vector<int> adj[V];
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);

    cout << "Following is a Topological Sort of\n";
    topologicalSort(adj, V);

    return 0;
}
