#include<bits/stdc++.h>
 
#define ll long long 
#define all(a) begin(a), end(a)
#define pll pair<ll, ll> 
#define vll vector<ll>
#define vvl vector<vll>
#define vpl vector<pll> 
#define f(i, s, e) for(ll i=s; i<e; i++)
#define cf(i, s, e) for(ll i=s; i<=e; i++)
#define rf(i, s, e) for(ll i=s; i>=e; i--) 
#define MOD(x) ((((x)%mod) + mod)%mod)
#define F first
#define S second
#define pb push_back 
using namespace std; 
typedef long double ld;
 
const ll INF = 1e18; 
const ll mod = 998244353;

void solve(){

    ll n, a, b;
    cin >> n >> a >> b;
    vll nums(n);
    f(i,0,n) cin >> nums[i];

    vll pfx(n+1);
    pfx[0]=0;
    f(i,0,n){
        pfx[i+1]=pfx[i]+nums[i];
    }

    multiset<ll> ms;
    vll ans(n+1, 0);
    f(i,1,n+1){
        if(i-b>0){
            ms.erase(ms.find(pfx[i-b-1]));
        }
        if(i>=a){
            ms.insert(pfx[i-a]);
        }
        if(!ms.empty())
        ans[i]=pfx[i]-*(ms.begin());
    }

    ll mx=-INF;
    f(i,a,n+1){
        mx=max(mx, ans[i]);
    }
    cout << mx << "\n";

}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    //ll t; cin >> t;
    //while(t--)
        solve();
}