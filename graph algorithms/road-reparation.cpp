#include <bits/stdc++.h>
// #include <unordered_set>
using namespace std;

#define f first
#define s second
#define pb push_back
// #define ll long long


using ll = long long;
using ld = long double;
using db = double;
using str = string; 
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

struct type{
    ll a,b,w;
};

vector<type> v;
vector<ll> l(MAX,0);
vector<ll> len(MAX,1);
void swap (long long &a,long long &b){
   
   
    ll temp=a;
    a=b;
    b=temp;

   }

   
  long long find(long long a){
  
    while(a!=l[a])
        a=l[a];
    return a;
  
  }

void solve(){
  
  ll n,m;
  cin>>n>>m;
  
  ll count=0;
  ll ans=0;

  for(int i=0;i<m;i++){
     
     type t;
     cin>>t.a>>t.b>>t.w;

     // v[i].a=t.a;
     // v[i].b=t.b;
     // v[i].w=t.w;
     v.push_back(t);
     
       }
  
  auto compare = [](type a,type b){
   
   return a.w<=b.w;
   
  };

  sort(v.begin(),v.end(),compare); 
  
  //union set
  // cout<<"yes"<<endl;
  for(int i=1;i<=n;i++)
    l[i]=i;

   auto same = [](ll a,ll b){

    return find(a)==find(b);
   
   };


   auto add = [](ll a,ll b){
    a=find(a);
    b=find(b);

    if(len[a]<len[b])
        swap(a,b);
     
    len[a]+=len[b];
    l[b]=a;


   };
  for(int i=0;i<m && count<n-1;i++){
    
    if(!(same(v[i].a,v[i].b))){
          ans+=v[i].w;
          add(v[i].a,v[i].b);
          count++;
    }

  }
  
  if(count!=(n-1)){
    cout<<"IMPOSSIBLE"<<endl;
    return;
  }
  cout<<ans<<endl;
}

int main(){

    clock_t tStart = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    init_code();

    solve();

    return 0;

}


//brute force

