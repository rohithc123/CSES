#include<bits/stdc++.h>
using namespace std;
// #define ll long long
#define F first
#define S second
#define vec vector
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
#define pll pair<ll, ll>
#define pdd pair<ld, ld>
#define pii pair<int, int>
#define pnn pair<Node*, Node*>
#define all(m) m.begin(), m.end()
#define rall(m) m.rbegin(), m.rend()
#define uid uniform_int_distribution
#define timeStamp() std::chrono::steady_clock::now()
#define unify(m) sort(all(m)); m.erase(unique(all(m)), m.end());
#define duration_micro(a) chrono::duration_cast<chrono::microseconds>(a).count()
#define duration_milli(a) chrono::duration_cast<chrono::milliseconds>(a).count()
#define fast cin.tie(0); cout.tie(0); cin.sync_with_stdio(0); cout.sync_with_stdio(0);
using str = string;
using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;

void init_code(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}

void solve(){
    ll n;
    cin>>n;

    //special base cases for n=1,2,3,4
    if(n==1){
        cout<<"1"<<endl;
        return;
    }

    if(n==2 || n==3){
        cout<<"NO SOLUTION"<<endl;
        return;
    }

    if(n==4){
        cout<<"2 3 1 4"<<endl;
        return;
    }

    vector<ll> v(n);

    iota(v.begin(),v.end(),1);

    for(int i=0;i<n;i+=2)
        cout<<v[i]<<" ";

    for(int i=1;i<n;i+=2)
        cout<<v[i]<<" ";
}


int main(){
    clock_t tStart = clock();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    init_code();

    solve();

	return 0;
}



