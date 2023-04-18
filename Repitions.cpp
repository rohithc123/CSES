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

const int MAX=1e9;

int main(){
    clock_t tStart = clock();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    init_code();

    string s;
    cin>>s;
    ll ans=1;
    ll count=1;

    //s.size()>=1
    char check=s[0];
    int n=s.size();

    for(int i=1;i<n;i++){
        if(check==s[i])
            count++;
        else
            count=1,check=s[i];

        ans=max(ans,count);
    }

    cout<<ans<<endl;

	return 0;
}



