#include<iostream>
using namespace std;
#define ll long long
ll prime[5000000];
void seive(){
    prime[0]=0;
    
    prime[1]=0;prime[2]=1;
    for(ll i=2;i<=5000000;i++){
prime[i]=0;
        
    }
    for(ll i=3;i<=5000000;i++){
        if(i%2==1){
            prime[i]=1;
        }
        
        
    }
    for(ll i=3;i<=5000000;i=i+2){
        if(prime[i]==1){
            for(ll j=i*i;j<5000000;j=j+i){
                prime[j]=0;
            }
        }
    }
    
    
}
ll prime2[5000000];
void seive2(){
    prime2[1]=1;
    
    prime2[0]=0;
    for(ll i=2;i<=5000000;i++){
prime2[i]=i;
        
    }
    for(ll i=2;i<=5000000;i=i+2){
     
            prime2[i]=2;
        
        
        
    }
    for(ll i=3;i*i<=5000000;i++){
        if(prime2[i]==i){
            for(ll j=2*i;j<=5000000;j=j+i){
                if(prime2[j]==j){
                    prime2[j]=i;
                }
            }
        }
    }
    
    
}
ll sett(ll n){
    ll sum=0;
    while(prime[n]!=1){
       sum++;
        n=n/prime[n];
    
    }
    sum++;
    return sum;
}
ll ans[5000000];

ll pre[5000000];
    int main(){
        cin.tie(NULL);
    seive();
    seive2();
    ll t;
    cin>>t;
    for(ll i=0;i<=5000000;i++){
        ans[i]=0;
        pre[i]=0;
    }
    
    for(ll i=1;i<=1000000;i++){
    if(prime[sett(i)]==1)ans[i]=1;
    else{
        ans[i]=0;
    }
    }
    for(ll i=1;i<=10000000;i++){

            pre[i]=pre[i-1]+ans[i];
        
    }
    /*
    for(ll i=1;i<=100000;i++){
    ll sum=0;
    ll cnt=0;
    for(ll j=1;j<=i;j++){
                if(i%j==0){
                    sum++;
                }
            }
            if(prime[sum]==1){
                cnt++;
            }
            ans[i]=cnt;
        }
    */
    while(t--){
        ll l,r;
        cin>>l>>r;
        ll cnt=0;
    cnt=pre[r]-pre[l-1];    
        cout<<cnt<<endl;
        
    }
    
}