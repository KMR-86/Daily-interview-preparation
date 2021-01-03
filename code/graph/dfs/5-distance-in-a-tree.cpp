#include<bits/stdc++.h>
using namespace std;

#define S 2002
bool visited[S]={0};
int t = -1;
vector<vector<int> >g(S);
void addEdge(int u, int v){
	g[u].push_back(v);
	g[v].push_back(u);
}
int dfsDistance(int u, int v, int count){
	visited[u]=1;
	//cout<<u<<" "<<count<<endl;
	if(u == v)return count;
	for(int i=0;i<g[u].size();i++){
		if(visited[g[u][i]] == 0){
		    t = dfsDistance(g[u][i], v, count+1);
		}
	}
	return t;
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++){
		int u,v;
		cin>>u>>v;
		addEdge(u,v);
	}
	int e;
	cin>>e;
	int min = 2000;
	int ans = 2000;
	while(e--){
		memset(visited, 0, sizeof(visited[0])*S);
		int v;
		cin>>v;
		dfsDistance(1, v, 0);
		//cout<<"t = "<<t<<endl;
		if(t<min){min = t;ans=v;}
		else if(t==min && ans>v)ans=v;
	}
	cout<<ans<<endl;

	return 0;
}
