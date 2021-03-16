/*
A vertex is said to be an articulation point in a graph if removal of the vertex and associated edges disconnects the graph.
So, the removal of articulation points increases the number of connected components in a graph.
Articulation points are sometimes called cut vertices.

Properties : 
1)If u is root of DFS tree and has 2 or more than 2 children, then the root / u is articulation point.
2)If u is a child node in the DFS tree , then u is an articulation point if any of its child cannot visit the ancestor of u
  via tree edge or back edge [this algo can be implemented by using discovery time & lowest discovery time reachable through tree or back edges
  i.e, u->v then if(low[v] >= disc[u]) then u is articulation point].

Time Complexity => O(V+E)
*/

#include <iostream>
#include <list>
#define NIL -1
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    void APUtil(int v, bool visited[], int disc[], int low[], int parent[], bool ap[]);

public:
    Graph(int V);
    void addEdge(int v, int w);
    void AP();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::APUtil(int u, bool visited[], int disc[], int low[], int parent[], bool ap[])
{
    static int time = 0;

    int children = 0;
    visited[u] = true;
    disc[u] = low[u] = ++time;

    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i)
    {
        int v = *i;
        if (!visited[v])
        {
            children++;
            parent[v] = u;
            APUtil(v, visited, disc, low, parent, ap);

            low[u] = min(low[u], low[v]);

            if (parent[u] == NIL && children > 1) //Property 1
                ap[u] = true;
            if (parent[u] != NIL && low[v] >= disc[u]) //Property 2
                ap[u] = true;
        }
        else if (v != parent[u])
            low[u] = min(low[u], disc[v]);
    }
}

void Graph::AP()
{
    bool *visited = new bool[V]; // To mark the visited nodes in dfs traversal
    int *disc = new int[V];      // For Discovery Time
    int *low = new int[V];       // For lowest discovery time reachable through tree or back edges
    int *parent = new int[V];    // To maintain the tree edges
    bool *ap = new bool[V];      // To mark the nodes which are Articulation Point

    for (int i = 0; i < V; i++)
    {
        parent[i] = NIL;
        visited[i] = false;
        ap[i] = false;
    }

    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            APUtil(i, visited, disc, low, parent, ap);

    for (int i = 0; i < V; i++)
        if (ap[i] == true)
            cout << i << " ";
}

/*
    1----0----3----4
     \   |
      \  |
       \ |
        2
*/

int main()
{
    cout << "Articulation points in first graph \n";
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);
    g.AP();

    return 0;
}
