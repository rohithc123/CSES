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



void solve(){

   int n,x;
   cin>>x>>n;

   set<int> s;
   multiset<int> ms;

   s.insert(0);
   s.insert(x);
   ms.insert(x-0);

   while(n--){
    int temp;
    cin>>temp;
    // cout<<temp<<endl;
    s.insert(temp);
    auto it=s.find(temp);
    int pre=*prev(it);
    int nxt=*next(it);

    ms.erase(ms.find(nxt-pre));
    ms.insert(temp-pre);
    ms.insert(nxt-temp);

    cout<<*ms.rbegin()<<" ";

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
