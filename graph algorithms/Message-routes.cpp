#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pb push_back
#define ll long long
 
// using ll = long long;
// using ld = long double;
// using db = double;
// using str = string;  // yay python!
 
// using pi = pair<int, int>;
// using pl = pair<ll, ll>;
// using pd = pair<db, db>;


// using vi = vector<int>;
// using vb = vector<bool>;
// using vl = vector<ll>;
// using vd = vector<db>;
// using vs = vector<str>;
// using vpi = vector<pi>;
// using vpl = vector<pl>;
// using vpd = vector<pd>;
 
 
// // pairs
// #define mp make_pair
// #define f first
// #define s second
 
// // vectors
// // oops size(x), rbegin(x), rend(x) need C++17
// #define sz(x) int((x).size())
// #define bg(x) begin(x)
// #define all(x) bg(x), end(x)
// #define rall(x) x.rbegin(), x.rend()
// #define sor(x) sort(all(x))
// #define rsz resize
// #define ins insert
// #define ft front()
// #define bk back()
// #define pb push_back
// #define eb emplace_back
// #define pf push_front
// #define ed endl
 
// #define lb lower_bound
// #define ub upper_bound
 
void init_code(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}

const int MAX=1e5+10;
// const ll NUM=1e5+10;
vector<vector<int>> v(MAX);
vector<int> parent(MAX,-1);
vector<int> dist(MAX,1e9);
vector<bool> visited(MAX,false);

void solve(){
  
 int n,m;
 cin>>n>>m;

 for(int i=0;i<m;i++)
 {
    int a,b;
    cin>>a>>b;
    // int x=min(a,b);
    // int y=max(a,b);
    v[a].push_back(b);
    v[b].push_back(a);
    
 }

 for(int i=1;i<MAX;i++){
    sort(v[i].begin(),v[i].end());
 }

 // priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> q;
queue<pair<int,int>> q;
  dist[1]=0;

  q.push({0,1});
  

  while(!q.empty()){
    ll d=q.front().f;
    ll u=q.front().s;

    q.pop();

    
    // if(d>dist[u])
        // continue;
    // int w=1;
    for(auto x:v[u]){
        if(!visited[x] && dist[x]>1+d){
        // cout<<x<<" ";
            dist[x]=1+d;
            parent[x]=u;
            // sort(ans[x].begin(),ans[x].end());
    visited[x]=true;
            q.push({d+1,x});
        }
    }
    // cout<<endl;
   

  }

  if(parent[n]==-1)
  {
    cout<<"IMPOSSIBLE"<<endl;
    return;
  }

  vector<int> ans;
  int i=n;
  ans.push_back(n);
  while(parent[i]!=-1){
     ans.push_back(parent[i]);
     i=parent[i];
  }
  cout<<ans.size()<<endl;

  reverse(ans.begin(),ans.end());

  for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<" ";
  }





}
 
    
int main(){
    // clock_t tStart = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    init_code();
    
    // cout<<"yes"<<endl;
    // int t;
    // cin>>t;

    // while(t--)    
    solve();

    return 0;
}
