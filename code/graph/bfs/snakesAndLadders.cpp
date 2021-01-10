#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > g(31);
int visited[31]= {0};
vector<int> dis(31);
void addEdge(int u, int v)
{
    g[u].push_back(v);
}
void emptyGraph()
{
    for(int i = 0; i < 31; i++)
    {
        g[i].clear();
    }
    memset(visited, 0, sizeof(visited[0])*31);
    fill(dis.begin(), dis.end(), INT_MAX);
}
void createBoard()
{
    emptyGraph();
    int n;
    cin>>n;
    map<int,int> laddersAndSnakes;

    for(int i = 0; i < n; i++)
    {
        int start,finish;
        cin>>start>>finish;
        laddersAndSnakes[start]=finish;
    }
    for(int i = 1; i <=29; i++)
    {
        for(int j = 1; j <= 6; j++)
        {
            int start = i;
            int end = i+j;

            if(end <= 30)
            {
                if(laddersAndSnakes[end] != 0)
                {
                    addEdge(start,laddersAndSnakes[end]);
                }
                else
                {
                    addEdge(start, end);
                }
            }

        }
    }
}

int bfsToFindDistance(int source)
{
    dis[source]=0;
    queue<int>q;
    q.push(source);
    visited[source]=2;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = 0; i < g[u].size(); i++)
        {
            int v = g[u][i];
            if(visited[v]==0)
            {
                dis[v]=dis[u]+1;
                visited[v]=1;
                q.push(v);
            }
        }
    }
    return dis[30];
}
void printGraph()
{
    for(int i = 0; i < 31; i++)
    {
        cout<<i<<" -> ";
        for(int j = 0; j<g[i].size(); j++)
        {
            cout<<g[i][j]<<" ";
        }
        cout<<endl;

    }
}
int main()
{
    //code
    int tc;
    cin>>tc;
    while(tc--)
    {
        createBoard();

        cout<<bfsToFindDistance(1);
        cout<<endl;

    }
    return 0;
}
