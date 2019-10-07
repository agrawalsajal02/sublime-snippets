#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define f(i,a,b) for(ll (i)=(a);(i)<(b);(i)++)
ll a[10000010];
ll dp[10000010];
int main(){
    ll t;
    cin>>t;
    while(t--){
ll n;
cin>>n;
f(i,0,n)cin>>a[i];
f(i,0,n+1){
    dp[i]=INT_MAX;
}
dp[0]=0;
f(i,0,n){
    if(dp[i]!=INT_MAX){
    for(ll j=i+1;j<=min(n-1,i+a[i]);j++){
        dp[j]=min(dp[j],dp[i]+1);
    }
}
}
//cout<<find(0,n)<<endl;
if(dp[n-1]!=INT_MAX){

cout<<dp[n-1]<<endl;
   
}
else{
    cout<<"-1"<<endl;
}



    }



}