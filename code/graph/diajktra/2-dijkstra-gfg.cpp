vector <int> dijkstra(vector<vector<int>> g, int src, int V)
{
    // Your code here
    bool visited[102]={0};
    vector<int> dis(102,INT_MAX);
    dis[src]=0;
    priority_queue<pair<int,int>,vector<pair<int,int> >, greater<pair<int,int> > >pq;
    pq.push(make_pair(0,src));
    while(!pq.empty()){
        pair<int,int> p = pq.top();
        pq.pop();
        int u = p.second;
        visited[u]=1;
        for(int i = 0; i < V; i++){
            int v = i;
            if(visited[v]==0 && g[u][v]!=0){
                if(dis[u]+g[u][v] < dis[v]){
                    dis[v]=dis[u]+g[u][v];
                    pq.push(make_pair(dis[v],v));
                }
            }
        }
    }
    return dis;
}
