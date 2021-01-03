bool visited[10002] = {0};
bool ans=0;
void dfs_node(vector<int> g[], int V,int node,int parent){
    visited[node]=1;
    for(int i=0;i<g[node].size();i++){
        if(visited[g[node][i]]==0 ){
            //cout<<g[node][i]<<" ";
            dfs_node(g,V,g[node][i],node);
        }
        else if (visited[g[node][i]]!=0 && parent != g[node][i]){
            ans = 1;
            break;
        }


    }
}
bool isCyclic(vector<int> g[], int V)
{
   // Your code here
   memset(visited,0,sizeof(visited[0])*10002);
   ans=0;

   for(int i=0;i<V;i++){
       if(visited[i] == 0){
           dfs_node(g,V,i,i);
           if(ans == 1) return ans;

       }

   }
   return ans;




}
