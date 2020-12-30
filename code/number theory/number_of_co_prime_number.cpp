#include<iostream>
#include<cstdio>
#define M 5000002
using namespace std;
long double eular[M];
long double added_eular_values[M];
void setting_eular_values(){
    eular[1]=1;
    for(int i=2;i<M;i++){
        eular[i]=i;
    }
    for(int i=2;i<M;i++){
        if(eular[i]==i){
            for(int j=i;j<M;j=j+i){
                eular[j]=eular[j]*(1.0-(1.0/i));
            }
        }
    }
}
void setting_added_eular_values(){
    added_eular_values[1]=1;
    for(int i=2;i<M;i++){
        added_eular_values[i]=added_eular_values[i-1]+eular[i]*eular[i];
    }
}



int main(){
    ///freopen("input.txt","r",stdin);
    ///freopen("output.txt","w",stdout);
    setting_eular_values();
    setting_added_eular_values();
    int a,b,c;
    cin>>c;
    for(int k=0;k<c;k++){
        cin>>a>>b;
        unsigned long long int ans=0;
        ans=added_eular_values[b]-added_eular_values[a-1];
        printf("Case %d: %llu\n",k+1,ans);


    }


return 0;
}
