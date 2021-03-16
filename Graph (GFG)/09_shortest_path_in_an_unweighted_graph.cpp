#include <bits/stdc++.h>
using namespace std;

void BFS(vector<int> adj[], int V, int s)
{
    bool visited[V] = {false};
    int dist[V];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    queue<int> q;

    visited[s] = true;
    q.push(s);
    dist[s] = 0;

    while (q.empty() == false)
    {
        int u = q.front();
        q.pop();

        for (int v : adj[u])
        {
            if (visited[v] == false)
            {
                dist[v] = dist[u] + 1;
                visited[v] = true;
                q.push(v);
            }
        }
    }

    for (int i = 0; i < V; i++)
        cout << dist[i] << " ";
}

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

/*
        1----3
      / |   /|
     0  |  / |
      \ | /  |
        2----4
*/

int main()
{
    int V = 5;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 1, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 2, 4);

    cout << "Shortest path from source : " << endl;
    BFS(adj, V, 0);

    return 0;
}
