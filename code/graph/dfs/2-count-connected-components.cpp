#include<bits/stdc++.h>
using namespace std;
#define S 1001
bool visited[S] = {0};
vector<vector<int > > g(S);

void addEdge(int u, int v){

	g[u].push_back(v);
	g[v].push_back(u);
}
void dfsNode(int u){
	visited[u] = 1;
	for(int i = 0; i < g[u].size(); i++){
		if(visited[g[u][i]] == 0){
			dfsNode(g[u][i]);
		}
	}
}

int countComponents(int n){
	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(visited[i] == 0){
			ans++;
			dfsNode(i);
		}
	}
	return ans;
}
int main (){

	int n,e;
	cin>>n>>e;
	while(e--){
		int u,v;
		cin>>u>>v;
		addEdge(u,v);
	}
	cout<<countComponents(n)<<endl;
	return 0;
}
