
// #include <bits/stdc++.h>
// // #include <unordered_set>
// using namespace std;

// #define f first
// #define s second
// #define pb push_back
// // #define ll long long


// using ll = long long;
// using ld = long double;
// using db = double;
// using str = string; 
// using pi = pair<int, int>;
// using pl = pair<ll, ll>;
// using pd = pair<db, db>;
// using vi = vector<int>;
// using vb = vector<bool>;
// using vl = vector<ll>;
// using vd = vector<db>;
// using vs = vector<str>;
// using vpi = vector<pi>;
// using vpl = vector<pl>;
// using vpd = vector<pd>;
// // pairs
// #define mp make_pair
// #define f first
// #define s second
// // vectors
// // oops size(x), rbegin(x), rend(x) need C++17
// #define sz(x) int((x).size())
// #define bg(x) begin(x)
// #define all(x) bg(x), end(x)
// #define rall(x) x.rbegin(), x.rend()
// #define sor(x) sort(all(x))
// #define rsz resize
// #define ins insert
// #define ft front()
// #define bk back()
// #define pb push_back
// #define eb emplace_back
// #define pf push_front
// #define ed endl
// #define lb lower_bound
// #define ub upper_bound




// void init_code(){
//     #ifndef ONLINE_JUDGE
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
//     #endif
// }

// const int MAX=1e5+10;

// struct type{
//     ll a,b,w;
// };

// vector<type> v;
// vector<ll> l(MAX,0);
// vector<ll> len(MAX,1);



// void solve(){
  
//   string a,b;
//   cin>>a>>b;

//   ll ans=0;
  
//   int n=a.size();
//   int m=b.size();

//   vector<int> check(m+1,0);

//   string temp;
//   temp+=" ";

//   for(auto x:b){
//     temp+=x;
//   }
  
//   int j=0;
//   int count=0;
//   for(int i=1;i<n;i++){
//     if(b[i]==b[j]){
//         count++;
//         check[i+1]=count;
//         j++;
//     }
//     else
//         count=0,j=0;
//   }

//   int i=0;
//   j=0;
//   // cout<<check[1]<<check[2]<<endl;
//   // for(auto x:check)
//     // cout<<x;
// // cout<<endl;

//   b=temp;
//   while(i<=n-m){
     

//     // cout<<i<<"s "<<j<<endl;

//      while(i<n && j<m && a[i]==b[j+1]){
//         // cout<<i<<endl;
//         j++,i++;
//      }
//      // i--;
//     // cout<<i<<" "<<j<<endl;

//      if(j==m){
//         ans++,j=check[j];
//      }

//      if(j<m && a[i]!=b[j+1]){
        
//         if(j==0)
//             i++;

//         j=check[j];
        

//      }
//      // i++;



//   }
//   cout<<ans<<endl;
  
// }

// int main(){

//     clock_t tStart = clock();
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL),cout.tie(NULL);
//     init_code();

//     solve();

//     return 0;

// }


// //brute force

#include <bits/stdc++.h>
// #include <unordered_set>
using namespace std;

 
 
void init_code(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}
 

using ll = long long;

  
void solve(){
  
 string a;
 cin>>a;
 int n=a.size();
 vector<int> ans(n,0);
 
 int j=0;
 int i=1;
 int len=0;
 while(i<n){
   
   if(a[len]==a[i]){
    len++;
    ans[i]=len;
    i++;
   }
   else{
    if(len==0)
        i++;
    else{
        len=ans[len-1];
    }
   }
 }
 
 // for(auto x:ans)
    // cout<<x<<" ";
 vector<int> print;
 j=ans[n-1];
 while(j>0){
    // cout<<ans[j]<<" ";
        print.push_back(j);
    j=ans[j-1];
 }
 sort(print.begin(),print.end());

 for(auto x:print)
    cout<<x<<" ";
  
}

int main(){

    // clock_t tStart = clock();
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL),cout.tie(NULL);
   init_code();

    solve();

    return 0;

}


//brute force

