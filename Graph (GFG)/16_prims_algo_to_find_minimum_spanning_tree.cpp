// Time Complexity => O(V*V)
// Which can be reduced to O(E*log(V)) by doing optmizations
// like using adjacency list in place of matrix and using minHeap

// Minimum Spanning Tree is only calculated for graphs which are
// undirected, weighted, connected

#include <bits/stdc++.h>
using namespace std;
#define V 4

int primMST(int graph[V][V])
{
    int key[V];
    fill(key, key + V, INT_MAX);
    key[0] = 0;

    int res = 0;
    bool mSet[V];

    for (int count = 0; count < V; count++)
    {
        int u = -1;

        for (int i = 0; i < V; i++)
            if ((!mSet[i]) && (u == -1 || key[i] < key[u]))
                u = i;

        mSet[u] = true;
        res += key[u];

        for (int v = 0; v < V; v++)
        {
            if ((graph[u][v] != 0) && (mSet[v] == false))
                key[v] = min(key[v], graph[u][v]);
        }
    }
    return res;
}

int main()
{
    int graph[V][V] = {
        {0, 5, 8, 0},
        {5, 0, 10, 15},
        {8, 10, 0, 20},
        {0, 15, 20, 0},
    };

    cout << primMST(graph);

    return 0;
}