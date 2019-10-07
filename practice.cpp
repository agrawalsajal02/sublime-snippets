//dijkstra algo
//n square algo
#include<bits/stdc++.h>
 using namespace std;
 #define ll long long int
 #define f(i,a,b) for(ll (i)=(a);(i)<(b);(i)++)
 vector< pair<ll,ll> >v[1000000];
 ll find_min(ll *weight,bool *visited,ll n){
  ll ans=-1;
  f(i,0,n){
    if(!visited[i]&&(ans==-1||weight[i]<ans)){
      ans=weight[i];
    }
  }
  return ans;
 }
 void dijkstra(ll n,ll m){
  set< pair<ll,ll> >s;
  bool visited[n];
  ll weight[n];
  f(i,0,n){
    weight[i]=INT_MAX;
  }
  weight[0]=0;
  f(i,0,n){
    visited[i]=0;
  }
f(i,1,n){
  s.insert({INT_MAX,i});
}
s.insert({0,0});
while(!s.empty()){
  auto temp=*s.begin();
  s.erase(s.begin());
  for(auto kk: v[temp.second]){
    ll wei=kk.second;
    ll vv=kk.first;
    if(!visited[vv]&&weight[temp.second]+wei<weight[vv]){
  if(s.find({weight[vv],vv})!=s.end()){
s.erase({weight[vv],vv});
  }
      weight[vv]=weight[temp.second]+wei;
   s.insert({weight[vv],vv}); 
    }
  }
}


f(i,0,n){
cout<<"shortest dis from "<<0<<" to "<<i<<" is "<<weight[i]<<endl;
}

 }

 int main(){
  ll n,m;
  cin>>n>>m;
 f(i,0,m){
ll x,y,weight;
cin>>x>>y>>weight;
v[x].push_back({y,weight});
 }
 dijkstra(n,m);
 

 
 } 