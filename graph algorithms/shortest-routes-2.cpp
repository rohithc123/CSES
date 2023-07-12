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
 
const int MAX=505;
vector<vector<long long>> v(MAX,vector<long long>(MAX,LLONG_MAX));
vector<bool> visited(MAX,false);
vector<vector<long long>> dist(MAX,vector<long long>(MAX,LLONG_MAX));

 // vector<long long> dist(MAX,LLONG_MAX);
vector<long long> ans;
vector<int> temp;
 
 
void solve(){
 
   ll n,m,q;
   cin>>n>>m>>q;
   
   for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++)
        if(i==j)
        dist[i][j]=0;
   }

   while(m--){
    ll a,b,c;
    cin>>a>>b>>c;
    dist[a][b]=min(c,dist[a][b]);
    dist[b][a]=min(c,dist[a][b]);
    
   }
   
   for(int k=1;k<=n;k++){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
           if(dist[i][k]!=LLONG_MAX && dist[k][j]!=LLONG_MAX)
           if(dist[i][j]>dist[i][k]+dist[k][j])
            dist[i][j]=dist[i][k]+dist[k][j];
        }
    }
   }

   while(q--){
    int x,y;
    cin>>x>>y;
    if(dist[x][y]==LLONG_MAX)
        dist[x][y]=-1;

    cout<<dist[x][y]<<endl;
   }
}
 
 
int main(){
    clock_t tStart = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    init_code();
 
    
    solve();
    return 0;
}
 