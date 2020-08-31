#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int V ;
    list < int > *adj;
    public :
    Graph( int V )
    {
        this->V = V ;
        adj = new list<int>[V];
    }
    void addEdge ( int u, int v ) ;
    int countEdges() ;
    void count_evenOdd();
};
void Graph :: addEdge ( int u, int v )
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int Graph :: countEdges()
{
    int sum = 0;
    for (int i = 0 ; i < V ; i++)
    sum += adj[i].size();
    return sum/2;
}
void Graph :: count_evenOdd()
{
    int even_degree=0,odd_degree=0;
    for (int i = 0 ; i < V ; i++)
    {
        int degree = adj[i].size();
        if(degree%2==0)
            even_degree++;
        else
            odd_degree++;
    }
    cout<<"No. of even vertices:"<<even_degree<<endl;
    cout<<"No. of odd vertices:"<<odd_degree<<endl;
}
int main()
{
    int V,E,u,v,w;
    cout<<"No. of Vertices:";
    cin>>V;
    cout<<"No. of Edges:";
    cin>>E;
    Graph g(V);
    for(int i=0;i<E;i++)
    {
        cin>>u;
        cin>>v;
        g.addEdge(u,v);
    }
    cout<<"No.of vertices : "<<V<<endl;
    g.count_evenOdd();
    cout <<"No.of edges : "<< g.countEdges() << endl;
    return 0;
}
