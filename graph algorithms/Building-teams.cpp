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
 
const int MAX=1e6+5;
vector<bool> visited(MAX,false);
vector<vector<int>> v(MAX);
 vector<int> ans(MAX,-1);


 bool dfs(int i,int prev){

    //checking if already assigned value conincides with current value
    if(ans[i]!=-1)
        return ans[i]!=prev;

    ans[i]= prev==1?2:1;

    for(auto x:v[i]){
        if(!dfs(x,ans[i]))
            return false;
    }

    return true;

 }
void solve(){
 int n,q;
 cin>>n>>q;


 while(q--){
    int a,b;
    cin>>a>>b;

    v[a].pb(b);
    v[b].pb(a);
 } 

 bool flag=true;

 for(int i=1;i<=n && flag;i++)
    flag=dfs(i,0);

 if(flag){
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
 }
 else
    cout<<"IMPOSSIBLE"<<endl;
 
}
 
 
int main(){
    clock_t tStart = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    init_code();
 
    
    solve();
    return 0;
}

