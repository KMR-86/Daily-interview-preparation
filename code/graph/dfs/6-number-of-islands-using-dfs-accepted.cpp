#include<bits/stdc++.h>
using namespace std;
int findIslands(vector<int> A[], int N, int M);


int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);


int tc;
cin>>tc;
while(tc--){
    int N,M;
    cin>>N>>M;
    vector<int>A[N];
    for(int i=0;i<N;i++){
        vector<int>temp(M);
        A[i]=temp;
        for(int j=0;j<M;j++){
            cin>>A[i][j];
        }
    }
    cout<<findIslands(A,N,M)<<endl;
}
return 0;

}


int dirX[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dirY[] = {1, -1, 0, 0, 1, -1, 1, -1};
bool visited [102][102] = {0};
void dfsNode(vector<int> A[], int N, int M, int x, int y){
    visited[x][y]=1;
    for(int i = 0; i < 8; i++){
            int nx = x+dirX[i];
            int ny = y+dirY[i];
            if(nx < N && ny < M && nx >= 0 && ny >= 0 ){

                //cout<<"new points "<<nx<<ny<<endl;
                if(visited[nx][ny] == 0 && A[nx][ny] == 1){
                    dfsNode(A,N,M,nx,ny);
                }
            }
        }
}
int findIslands(vector<int> A[], int N, int M) {

    // Your code here
    memset(visited,0,sizeof(visited[0][0])*102*102);
    int ans=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){

            if(visited[i][j]==0 && A[i][j] == 1){
                ans++;
                //cout<<"the island points "<<i<<j<<endl;
                dfsNode(A,N,M,i,j);
            }
        }
    }
    return ans;
}
