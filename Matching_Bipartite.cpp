#include <iostream>
#include <string.h>
using namespace std;
int M=0,N=0;
bool bpm(bool** bpGraph, int u, bool seen[], int matchR[])
{
    for (int v = 0; v < N; v++)
    {
        if (bpGraph[u][v] && !seen[v])
        {
            seen[v] = true;
            if (matchR[v] < 0 || bpm(bpGraph, matchR[v], seen, matchR))
            {
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}
int maxBPM(bool** bpGraph)
{
    int matchR[N];
    memset(matchR, -1, sizeof(matchR));
    int result = 0;
    for (int u = 0; u < M; u++)
    {
        bool seen[N];
        memset(seen, 0, sizeof(seen));
        if (bpm(bpGraph, u, seen, matchR))
            result++;
    }
    return result;
}
int main()
{
    cout << "Enter the number of applicants and jobs : ";
    cin>>M>>N;
    cout << "Enter the incidence matrix of the graph : \n";
    bool** bpGraph = new bool*[M];
    for(int i=0; i<M; i++)
    {
        bpGraph[i] = new bool[N];
        for(int j=0;j<N;j++)
        {
            cin>>bpGraph[i][j];
        }
    }
    cout << "Maximum number of applicants that can get a job is : " <<
    maxBPM(bpGraph);
    return 0;
}
