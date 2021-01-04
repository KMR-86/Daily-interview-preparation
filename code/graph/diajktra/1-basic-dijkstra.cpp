#include<bits/stdc++.h>
#define S 11
using namespace std;
vector<vector<pair<int, int> > > g(S);
int visited[S] = {0};
vector<int> dis(S,INT_MAX);
void addEdge(int u, int v, int w){
    g[u].push_back(make_pair(w,v));
    g[v].push_back(make_pair(w,u));
}
int getEdgeWeight(int u, int v){
    for(int i = 0; i < g[u].size(); i++){
        if( v == g[u][i].second){
            return g[u][i].first;
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
        pq.pop();
        visited[u] = 2;
        for(int i=0; i<g[u].size(); i++){
            int v = g[u][i].second;
            if(visited[v] != 2){
                int duv = getEdgeWeight(u,v);
                if(dis[u]+duv < dis[v]){
                    dis[g[u][i].second] = dis[u]+duv;
                    pq.push(make_pair(dis[v],v));
                    visited[v] = 1;
                }
            }
        }

    }
}

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

int tc;
addEdge(1,2,9);
addEdge(2,3,2);
addEdge(1,3,1);
addEdge(1,4,7);
addEdge(2,4,2);
addEdge(2,8,2);
dijkstra(1);
for(int i=0;i<S;i++){
    cout<<dis[i]<<" ";
}


return 0;
}


