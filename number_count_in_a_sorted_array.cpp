#include<bits/stdc++.h>
using namespace std;
int my_binary_search(int a[],int n,int target){

    int l=0,h=n-1,mid;
    while(l<=h){
        mid=(l+h)/2;
        if(a[mid]==target){
            return mid;
        }
        else if(a[mid]<target){
            l=mid+1;
        }
        else if(a[mid]>target){
            h=mid-1;
        }
    }
    return -1;
}
int my_binary_search_lowest_index(int a[],int n,int target){

    int l=0,h=n-1,mid,ans=-1;
    while(l<=h){
        mid=(l+h)/2;
        if(a[mid]==target){
            ans=mid;
            h=mid-1;
        }
        else if(a[mid]<target){
            l=mid+1;
        }
        else if(a[mid]>target){
            h=mid-1;
        }
    }
    return ans;
}
int my_binary_search_highest_index(int a[],int n,int target){

    int l=0,h=n-1,mid,ans=-1;
    while(l<=h){
        mid=(l+h)/2;
        if(a[mid]==target){
            ans=mid;
            l=mid+1;
        }
        else if(a[mid]<target){
            l=mid+1;
        }
        else if(a[mid]>target){
            h=mid-1;
        }
    }
    return ans;
}
int count_the_numbers(int a[],int n,int target){
    return my_binary_search_highest_index(a,n,target)-my_binary_search_lowest_index(a,n,target)+1;
}
int main(){
    int n;
    cout<<"enter how many numbers "<<endl;
    cin>>n;
    int a[n];
    cout<<"enter the numbers"<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int s;
    cout<<"inter the number you want to count\n";
    cin>>s;
    cout<<count_the_numbers(a,n,s)<<endl;

return main();
}
