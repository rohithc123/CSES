#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ld = long double;
using db = double;
using str = string;  // yay python!
 
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;
 
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>;
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;
 
 
// pairs
#define mp make_pair
#define f first
#define s second
 
// vectors
// oops size(x), rbegin(x), rend(x) need C++17
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define sor(x) sort(all(x))
#define rsz resize
#define ins insert
#define ft front()
#define bk back()
#define pb push_back
#define eb emplace_back
#define pf push_front
#define ed endl
 
#define lb lower_bound
#define ub upper_bound
 
void init_code(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}
 
const int MAX=2510;
const ll INF=1e16;
const ll NINF=-1e16;

 
struct edge{
    ll u;
    ll v;
    ll w;
};
 
vector<edge> v;
vector<bool> visited(MAX,false);
// vector<long long> dist(MAX,LLONG_MAX);

 vector<ll> dist(MAX,INF);
vector<long long> ans;
vector<int> temp;
void solve(){

  ll n,m;
  cin>>n>>m;

  while(m--){
    edge e;
    cin>>e.u>>e.v>>e.w;

    e.w*=-1;
    v.push_back(e);
  }
  
  dist[1]=0;

//caclulating distance
  for(int i=0;i<n;i++){
    for(edge x:v){
     ll u=x.u;
     ll v=x.v;
     ll w=x.w;
  // cout<<u<<" "<<v<<endl;
     if(dist[u]==INF)
        continue;
     // cout<<dist[1]<<endl;

     dist[v]=min(dist[v],dist[u]+w);
    // cout<<dist[v]<<" "<<v<<endl;
     //may go beyonf -ve 
     dist[v]=max(dist[v],NINF);
    }
  }


//checking for loop
  for(int i=0;i<n;i++){
    for(edge x:v){
     ll u=x.u;
     ll v=x.v;
     ll w=x.w;
  // cout<<u<<" "<<v<<endl;
     if(dist[u]==INF)
        continue;
     // cout<<dist[1]<<endl;

     dist[v]=max(dist[v],NINF);
     //since we already calculated min this value must be same
     if(dist[v]>dist[u]+w)
        dist[v]=NINF;
    }
  }
  
  if(dist[n]==INF || dist[n]==NINF){
    cout<<"-1";
    return;
}

  cout<<-1*dist[n]<<endl;
 

}
 
 
int main(){
    clock_t tStart = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    init_code();
 
    
    solve();
    return 0;
}
 