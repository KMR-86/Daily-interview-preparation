bool visited[10001]={0};
vector<pair<int,int> > endTimer;
int timeCount=0;
void dfsNode(int u, vector<int> adj[]){
    visited[u] = 1;
    for(int i=0;i<adj[u].size();i++){
        if(visited[adj[u][i]] == 0){
            dfsNode(adj[u][i], adj);
        }
    }
    timeCount++;
    endTimer.push_back(make_pair(timeCount,u));
}
vector<int> topoSort(int V, vector<int> adj[]) {
    // Your code here
    memset(visited,0,sizeof(visited[0])*10001);
    endTimer.clear();
    for(int i=0;i<V;i++){
        if(visited[i] == 0){
            dfsNode(i,adj);
        }
    }
    sort(endTimer.begin(),endTimer.end());
    reverse(endTimer.begin(),endTimer.end());
    vector<int>ans;
    for(int i=0;i<V;i++){
        ans.push_back(endTimer[i].second);
    }
    return ans;
}
