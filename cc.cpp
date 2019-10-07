//written by sajal agrawal
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define f(i,a,b) for(ll (i)=(a);(i)<(b);(i)++)
vector<ll>v[100100];
vector<ll>v2[100100];
map< pair<ll,ll> , bool >m;
ll dijstra(ll src,ll d,ll n,ll ed){
  priority_queue<pi,vector<pi>,greater<pi> > pq;
ll dis[n];
ll vis[n];
f(i,1,n+1){
  vis[i]=0;
dis[i]=INT_MAX;
}

dis[src]=0;

q.push({0,src});


while(!q.empty()){
  auto pp=q.top();
  q.pop();
  ll from=pp.second;
  vis[from]=1;
  
  for(ll to: v[from]){
       ll newval=0;
       if(m[make_pair(from,to)]==0){
newval=1;
       }
        if(dis[to]>dis[from]+newval&&(!vis[to])){
//q.erase({dis[to],to});
dis[to]=newval+dis[from];
q.push({-dis[to],to});
    }



  }
}
if(dis[d]==INT_MAX){
    return -1;
}
return dis[d];
}

int main(){
ll t;
cin>>t;
while(t--){
ll n,e;
cin>>n>>e;
f(i,0,e){
    ll x,y,z;
    cin>>x>>y;
v[x].push_back(y);
v[y].push_back(x);
m[make_pair(x,y)]=1;
}
ll s,d;
cin>>s>>d;
cout<<dijstra(s,d,n,e)<<endl;

for(ll w=0;w<=n;w++){
  v[w].clear();
}
        /*for (auto& q : v) {
   q.clear();
}*/


}}