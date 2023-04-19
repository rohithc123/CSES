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

    vector<int> ans(n+1,0);


    if(((n*(n+1)/2)%2)!=0){
        cout<<"NO"<<endl;
        return;
    }

    cout<<"YES"<<endl;
    if(n%2==0){
        bool flag=true;
        for(int i=1;i<=n;){
           ans[i]=1;
           
           if(flag)
            i+=3;
           else
            i++;

           flag=!flag;
        }

      cout<<n/2<<endl;
      for(int i=1;i<=n;i++)
        if(ans[i]==1)
         cout<<i<<" ";
     cout<<endl;

      cout<<(n)/2<<endl;
      for(int i=1;i<=n;i++)
        if(ans[i]==0)
        cout<<i<<" ";
    }
    else
    {
        bool flag=false;
        for(int i=1;i<=n;i++){
            ans[i]=1;
            if(i%2==0)
                i+=2;
            flag=!flag;

        }


      cout<<(n+1)/2<<endl;
      for(int i=1;i<=n;i++)
        if(ans[i]==1)
        cout<<i<<" ";
     cout<<endl;


      cout<<n/2<<endl;
      for(int i=1;i<=n;i++)
        if(ans[i]==0)
        cout<<i<<" ";
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



