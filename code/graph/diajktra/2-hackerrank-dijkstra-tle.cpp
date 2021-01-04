#include<bits/stdc++.h>
#define S 3002
using namespace std;
vector<vector<pair<int, int> > > g(S);
vector<int> dis(S,INT_MAX);
bool visited[S]={0};
void addEdge(int u, int v, int w){
    g[u].push_back(make_pair(w,v));
    g[v].push_back(make_pair(w,u));
}

int getEdgeWeight(int u, int v){
    int minEdge = INT_MAX;
    for(int i = 0; i < g[u].size(); i++){

        if( v == g[u][i].second){
            if(minEdge > g[u][i].first)minEdge=g[u][i].first;
        }
    }
    return minEdge;
}
void printGraph(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j< g[i].size(); j++){
            cout<<i<<" "<<g[i][j].second<<" "<<g[i][j].first<<endl;
        }
    }
}
void dijkstra(int s){
    dis[s]=0;
    priority_queue<pair<int, int>, vector<pair<int, int > >, greater<pair<int, int > > > pq;
    pq.push(make_pair(0,s));
    while(!pq.empty()){
        pair<int,int> p = pq.top();
        int u = p.second;
        visited[u]=1;
        pq.pop();
        for(int i=0; i<g[u].size(); i++){
            int v = g[u][i].second;

            int duv = getEdgeWeight(u,v);
            if(dis[u]+duv < dis[v] && visited[v] == 0){
                dis[v] = dis[u]+duv;
                pq.push(make_pair(dis[v],v));

            }
        }

    }
}

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);


int tc;
cin>>tc;
while(tc--){
    fill(dis.begin(), dis.end(), INT_MAX);
    memset(visited,0,sizeof(visited[0])*S);
    for(int i = 0; i<S; i++){
        g[i].clear();
    }
    int n,m;
    cin>>n>>m;
    while(m--){
        int u,v,w;
        cin>>u>>v>>w;
        addEdge(u,v,w);

    }
    int s;
    cin>>s;
    dijkstra(s);
    for(int i=1;i<=n;i++){
        if(i!=s && dis[i]==INT_MAX)cout<<"-1 ";
        else if(i!=s)cout<<dis[i]<<" ";
    }
    cout<<endl;

}





return 0;
}

/*
2
5 3
1 2 10
1 3 6
2 4 8
2
4 4
1 2 24
1 4 20
3 1 3
4 3 12
1




correct output
10 16 8 -1
24 3 15



1
20 54
1 7 45
2 14 15
3 7 29
4 1 48
5 1 66
6 7 17
7 14 15
8 14 43
9 1 27
10 1 33
11 14 64
12 14 27
13 7 66
14 7 54
15 14 56
16 7 21
17 1 20
18 1 34
19 7 52
20 14 14
9 14 9
15 1 39
12 1 24
9 1 16
1 2 33
18 1 46
9 1 28
15 14 3
12 1 27
1 2 5
15 1 34
1 2 28
9 7 16
3 7 23
9 7 21
9 14 19
3 1 20
3 1 5
12 14 19
3 14 2
12 1 46
3 14 5
9 14 44
6 14 26
9 14 16
9 14 34
6 7 42
3 14 27
1 7 9
1 7 41
15 14 19
12 7 13
3 7 10
1 7 2
17
*/


