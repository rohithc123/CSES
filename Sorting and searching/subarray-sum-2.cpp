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




void solve(){

 int n,a,b;
 cin>>n>>a>>b;

 vector<int> v(n);

 for(auto &x:v)
    cin>>x;
 
 ll ans=LLONG_MIN;
 
 vector<ll> hash(n+1);
 set<pair<ll,ll>> s;

 for(int i=1;i<=n;i++)
    hash[i]=hash[i-1]+v[i-1];

 for(int i=a;i<=b;i++)
    s.insert({hash[i],i});


 for(int i=1;i<=n-a+1;i++){
    
   ans=max(ans,(*s.rbegin()).f-hash[i-1]);

   auto it=s.find({hash[i+a-1],i+a-1});

   s.erase(it);

   if(i+b<=n)
    s.insert({hash[i+b],i+b});

 }

 cout<<ans<<endl;




 // cout<<ans<<endl;
 

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


//brute force

