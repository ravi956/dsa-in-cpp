// Time Complexity => theta(V*V)
// Which can be reduced to O(E*log(V)) by doing optmizations
// like using adjacency list in place of matrix and using minHeap

// It does not work for negative weight edges
// Shortest Path may change if we add a similar weigth to all the edges of the original graph
// Multiplying each weight of the original graph by a similar factor does not change the shortest path of the graph

#include <bits/stdc++.h>
using namespace std;
#define V 4

vector<int> dijkstra(int graph[V][V], int src)
{
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    vector<bool> fin(V, false);

    for (int count = 0; count < V - 1; count++)
    {
        int u = -1;

        for (int i = 0; i < V; i++)
            if (!fin[i] && (u == -1 || dist[i] < dist[u]))
                u = i;

        fin[u] = true;

        for (int v = 0; v < V; v++)
            if (graph[u][v] != 0 && fin[v] == false)
                dist[v] = min(dist[v], dist[u] + graph[u][v]);
    }
    return dist;
}

int main()
{
    int graph[V][V] = {
        {0, 50, 100, 0},
        {50, 0, 30, 200},
        {100, 30, 0, 20},
        {0, 200, 20, 0},
    };

    for (int x : dijkstra(graph, 0))
    {
        cout << x << " ";
    }

    return 0;
}