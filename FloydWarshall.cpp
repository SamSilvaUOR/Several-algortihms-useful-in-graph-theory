#include<bits/stdc++.h>
#define INF 99999
using namespace std;
int main()
{
    int V,i,j,k;
    printf("Enter the number of vertices of the graph : ");
    scanf("%d", &V);
    int graph[V][V], dist[V][V];
    printf("Enter the adjacency matrix for the graph : \n");
    string temp;
    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
        {
            printf("graph[%d][%d]=",i,j);
            cin>>temp;
            if(temp=="INF")
                graph[i][j] = INF;
            else
                graph[i][j] = atoi(temp.c_str());
        }
    }
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];
    for (k = 0; k < V; k++)
    {
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
        }
    }
    printf ("The following matrix shows the shortest distances"
    " between every pair of vertices : \n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf ("%7d", dist[i][j]);
        }
        printf("\n");
    }
    return 0;
}
