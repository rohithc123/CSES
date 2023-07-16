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
 
const int MAX=1e5+10;

vector<vector<pair<long long,long long>>> v(MAX);
vector<bool> visited(MAX,false);

// vector<long long> dist(MAX,LLONG_MAX);

vector<long long> dist(MAX,LLONG_MAX);
vector<long long> temp(MAX,0);
vector<long long> ans;
void solve(){

  ll n,m,k;
  cin>>n>>m>>k;

  while(m--){
    
    ll a,b,w;
    cin>>a>>b>>w;
    v[a].push_back({b,w});
    // v[b].push_back({a,w});


  }
  
  //type vector<type> greater<type>
  //wierd way for repersenting inverse pq
  priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> q;
  vector<vector<long long>> ans(n+1,vector<long long>(k+1,1e16));
  dist[1]=0;

  q.push({0,1});

  while(!q.empty()){
    ll u=q.top().s;
    ll d=q.top().f;
    q.pop();

    if(d>ans[u][k-1])
        continue;

    for(auto [x,w]:v[u]){

        if(ans[x][k-1]>w+d){
            ans[x][k-1]=w+d;
            sort(ans[x].begin(),ans[x].end());
            q.push({d+w,x});
        }
    }
   

  }


 
 for(int i=0;i<k;i++)
  cout<<ans[n][i]<<" ";
 
}
 
 
int main(){
    clock_t tStart = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    init_code();
 
    
    solve();
    return 0;
}
 