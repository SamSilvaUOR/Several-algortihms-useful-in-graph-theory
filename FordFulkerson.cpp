#include <iostream>
#include <limits.h>
#include <string.h>
#include <queue>
using namespace std;
int V = 0;
bool bfs(int** rGraph, int s, int t, int parent[])
{
    bool visited[V];
    memset(visited, 0, sizeof(visited));
    queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v=0; v<V; v++)
        {
            if (visited[v]==false && rGraph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return (visited[t] == true);
}
int fordFulkerson(int** graph, int s, int t)
{
    int u, v;
    int** rGraph = new int*[V];
    for(int i = 0; i < V; i++)
    {
        rGraph[i] = new int[V];
        for(int j = 0; j < V; j++)
        {
            rGraph[i][j] = graph[i][j];
        }
    }
    int parent[V];
    int max_flow = 0;
    while (bfs(rGraph, s, t, parent))
    {
        int path_flow = INT_MAX;
        for (v=t; v!=s; v=parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }
        for (v=t; v != s; v=parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
        max_flow += path_flow;
    }
    return max_flow;
}
int main()
{
    cout << "Enter the number of vertices in the graph : ";
    cin >> V;
    cout << "Enter the adjacency matrix of the graph : \n";
    int** graph = new int*[V];
    for(int i = 0; i < V; i++)
    {
        graph[i] = new int[V];
        for(int j = 0; j < V; j++)
        {
            cin >> graph[i][j];
        }
    }
    cout << "The maximum possible flow is " << fordFulkerson(graph, 0, 5);
    return 0;
}
