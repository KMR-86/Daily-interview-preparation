#include<bits/stdc++.h>
#define S 10
using namespace std;
vector<vector<int> > g(S+1);
bool visited[S+1] = {0};
int startTime[S+1] = {0};
int endTime[S+1] = {0};
int timeCount = 0;
void addEdge(int u, int v){
    g[u].push_back(v);
    g[v].push_back(u);
}
void dfsNode(int u){
    cout<<u<<" ";
    visited[u] = 1;
    startTime[u] = timeCount;
    timeCount++;

    for(int i=0;i<g[u].size();i++){
        if(visited[g[u][i]] == 0){
            dfsNode(g[u][i]);
        }
    }
    timeCount++;
    endTime[u] = timeCount;
}
void dfs(){
    for(int i=1;i<=S;i++){
        if(visited[i] == 0){
            dfsNode(i);
        }
    }
}
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);

int tc;

addEdge(1,2);
addEdge(4,2);
addEdge(3,4);
addEdge(1,9);
addEdge(3,8);
dfs();
cout<<endl;
for(int i = 1; i <= S; i++){
    cout<<startTime[i]<<" ";
}
cout<<endl;

vector<pair<int,int> >indexValuePairList;
for(int i = 1; i <= S; i++){
    cout<<endTime[i]<<" ";
    indexValuePairList.push_back(make_pair(endTime[i],i));
}
cout<<endl;
sort(indexValuePairList.begin(), indexValuePairList.end());
vector<int>toposort(S);
for(int i = 0; i <= S; i++){
    toposort[i] = indexValuePairList[i].second;
}
reverse(toposort.begin(),toposort.end());
for(int i = 0; i <= S; i++){
    cout<<toposort[i]<<" ";
}
return 0;
}



