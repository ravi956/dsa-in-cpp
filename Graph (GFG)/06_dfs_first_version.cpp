// Given an undirected graph and a source vertex 's' ,
// print D.F.S from given source

#include <bits/stdc++.h>
using namespace std;

void DFSutil(vector<int> adj[], int s, bool visited[])
{
    visited[s] = true;
    cout << s << " ";

    for (int u : adj[s])
    {
        if (visited[u] == false)
            DFSutil(adj, u, visited);
    }
}

void DFS(vector<int> adj[], int V, int s)
{
    bool visited[V] = {false};

    DFSutil(adj, s, visited);
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

    cout << "Following is Depth First Traversal: " << endl;
    DFS(adj, V, 0);

    return 0;
}
