#include<bits/stdc++.h>
using namespace std;

long long int binary_exp(long long int a,long long int n){
    long long ans=1;
    long long s=a;
    if(n<0){cout<<"the power can not be negative\n";return -1111111111111;}
    while(n!=0){
        if(n & 1 == 1){
            ans=ans*s;
        }
        s=s*s;
        n=n>>1;
        ///cout<<n<<endl;
    }
    return ans;


}
int main(){

    long long a,n;
    cin>>a>>n;
    cout<<a<<"^"<<n<<" = "<<binary_exp(a,n)<<endl;
    main();

return 0;
}
