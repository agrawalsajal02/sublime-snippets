#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ll n;
cin>>n;
ll a[2*n];
    for(ll i=0;i<2*n;i++){
        cin>>a[i];
    }
    sort(a,a+2*n);
ll dd=(a[n-1]+a[n])/2;
cout<<dd<<endl;


}
