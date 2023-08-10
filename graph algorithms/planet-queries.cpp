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




  vector<ll> parent(1e6);
  vector<vector<ll>> binary_lifting(1e6,vector<ll>(32,0));
void solve(){

  ll n,q;
  cin>>n>>q;


  for(int i=1;i<=n;i++){
    int x;
    cin>>x;
    binary_lifting[i][0]=x;
  }

  // for(int i=1;i<=n;i++)
    // binary_lifting[i][0]=parent[i];

  for(int i=1;i<31;i++){
    for(int j=1;j<=n;j++){
        binary_lifting[j][i]=binary_lifting[binary_lifting[j][i-1]][i-1];
    }
  }

  while(q--){
    ll a,b;
    cin>>a>>b;

    // ll ans;

    for(int j=0;j<31 && b!=0 ;j++){
        if(b & (1<<j)){
            // cout<<j<<endl;
            a=binary_lifting[a][j];
            b-=(1<<j);
        }
    }

    cout<<a<<endl;
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


//brute force

