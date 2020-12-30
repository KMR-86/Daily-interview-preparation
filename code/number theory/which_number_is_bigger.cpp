#include<bits/stdc++.h>
using namespace std;
int main(){
    double sum=0;
    for(int i=1;i<=300;i++){
        sum+=log10(i);
    }
    cout<<sum<<endl;
return 0;
}
