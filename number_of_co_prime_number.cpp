#include<bits/stdc++.h>
using namespace std;
int *primes;
int *seive(int n){
    int *prime_bool = new int[n+1];
    for(int i = 0; i<= n;i++){
        prime_bool[i]=0;
    }
    prime_bool[1]=1;
    for(int i=2;i<=n;i++){
        if(prime_bool[i]==0 && (long long)i*i <= n){
            for(int j=i*i;j<=n;j=j+i){
                prime_bool[j]=1;
            }
        }
    }

    return prime_bool;

}
int num_of_co_primes(int n){

    float ret=n;
    for(int i=2;i<=n;i++){
        if(primes[i]==0 && n%i==0){
            ret=ret*(1-(1.0/i));
            //printf("i=%d, ret=%f ",i,ret);
        }

    }
    return ret;
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    primes=seive(5000000);
    int a,b,c;
    cin>>c;
    for(int k=0;k<c;k++){
        cin>>a>>b;
        long long int ans=0;
        for(int i=a;i<=b;i++){
            int t=num_of_co_primes(i);
            ans=ans+t*t;
        }
        cout<<"Case "<<k+1<<": "<<ans<<"\n";

    }


return 0;
}
