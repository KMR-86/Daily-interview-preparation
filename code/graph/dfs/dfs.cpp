#include<bits/stdc++.h>
using namespace std;
#define S 6
vector< vector <int > > g(S+1);
int visited[S+1]={0};
void addEdge(int u, int v){
    g[u].push_back(v);
    g[v].push_back(u);

}

void printGraph(vector<vector<int > >g){
    for(int i=0;i<g.size();i++){
        cout<<i;
        for(int j=0;j<g[i].size();j++){
            cout<<" -> "<<g[i][j];
        }
        cout<<endl;
    }

}

void dfsNode(int u){
    visited[u] = 1;
    cout<<u<<" ";
    for(int i = 0; i < g[u].size(); i++){
        if(visited[g[u][i]] == 0){
            dfsNode(g[u][i]);
        }
    }

}

void dfs(){
    for(int i = 1; i <= S; i++){
        if(visited[i] == 0){
            dfsNode(i);
        }
    }

}

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

int tc;
addEdge(1,2);
addEdge(2,3);
addEdge(4,5);
addEdge(6,1);
printGraph(g);
dfs();
return 0;
}



