#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pb push_back
// #define ll long long


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

// const int MAX=1e5+10;


int MAX=1e6+10;


void solve(){

 int n,m;
 cin>>n>>m;
 // cout<<"y"; 

 vector<int> v(n+1);
vector<int> value(n+1);

// int i=1;
 for(int i=1;i<=n;i++){
    int x;
    cin>>x;
    v[i]=x;
    value[x]=i;
 }

 auto swap = [&](int &a,int &b){
  int temp=a;
  a=b;
  b=temp;
 };

int ans=1;
for(int i=2;i<=n;i++){
    if(value[i-1]>value[i])
        ans++;
}
// cout<<ans<<endl;


  set<pair<int,int>> temp;
 while(m--){
  
  int a,b;
  cin>>a>>b;

   if(v[a]-1>0)
    temp.insert({v[a]-1,v[a]});

   if(v[a]+1<=n)
    temp.insert({v[a],v[a]+1});

   if(v[b]-1>0)
    temp.insert({v[b]-1,v[b]});

   if(v[b]+1<=n)
    temp.insert({v[b],v[b]+1});

  for(auto x:temp){
    ans -= value[x.f]>value[x.s];
    
}
  swap(v[a],v[b]);
  value[v[a]]=a;
  value[v[b]]=b;

  for(auto x:temp)
    ans+=value[x.f]>value[x.s];

temp.clear();
  cout<<ans<<endl;

 }

}

int main(){

    clock_t tStart = clock();
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
