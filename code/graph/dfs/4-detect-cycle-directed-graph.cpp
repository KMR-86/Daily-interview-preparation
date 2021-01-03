void dfs_in_one_node(vector<int>g[], int N, int node,vector<bool> &visited,bool &ans,int start_node){
    visited[node]=true;

    for(int i=0;i<g[node].size();i++){
        if(visited[g[node][i]]==0){

            dfs_in_one_node(g,N,g[node][i],visited,ans,start_node);
        }
        else{
            ans=true;
            break;
        }
    }
    visited[node]=false;

}


bool isCyclic(int V, vector<int> adj[])
{


    bool ans=false;

    for(int i=0;i<V;i++){
        vector<bool>visited(V,0);
        dfs_in_one_node(adj,V,i,visited,ans,i);


    }
    return ans;
}
