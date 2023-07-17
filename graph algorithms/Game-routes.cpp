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
const int MOD=1e9+7;


vector<vector<long long>> v(MAX);
vector<bool> visited(MAX,false);

// vector<long long> dist(MAX,LLONG_MAX);

vector<long long> ans(MAX,0);
vector<long long> indegree(MAX,0);



void solve(){
  ll n,m;
  cin>>n>>m;

  while(m--){
    
    ll a,b;
    cin>>a>>b;
    v[a].push_back(b);
    // v[b].push_back({a,w});
    indegree[b]++;


  }

  //using top sorting since dfs was giving tle

  queue<long long> q;

  //removing nodes which are not part of the part in the ans that is why i starts from 2

  for(int i=2;i<=n;i++){

    if(indegree[i]==0)
        q.push(i);

  }

  while(!q.empty()){

    int u=q.front();
    q.pop();
    // cout<<u<<endl;

    for(auto x:v[u]){

        --indegree[x];
        if(indegree[x]==0 && x!=1)
            q.push(x);
    }
  }
  
  ans[1]=1;
  q.push(1);
  

  while(!q.empty()){

    int u=q.front();
    q.pop();

    for(auto x:v[u]){

        --indegree[x];
        ans[x]+=ans[u];
        ans[x]%=MOD;
        if(indegree[x]==0)
            q.push(x);
    }
  }
  

  
// for(auto x:ans)
    // cout<<x<<" "<<endl;
  cout<<ans[n]<<endl;
  
}
 
 
int main(){
    clock_t tStart = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    init_code();
 
    
    solve();
    return 0;
}
 