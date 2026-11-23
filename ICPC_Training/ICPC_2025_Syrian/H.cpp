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
    
    ll n; cin >> n;
    vll parities(n, 0);
    ll x;
    f(i,0,n){
        cin >> x;
        parities[i]=x%2;
    }

    vll dp(n, 0);
    dp[n-1]=(parities[n-1]+1)%2;
    for(ll i=n-2;i>=0; i--){
        if(dp[i+1]==0){
            dp[i]=1;
        } else {
            dp[i]=(parities[i]+1)%2;
        }
    }

    if(dp[0]==0){
        cout << "Second\n";
    } else cout << "First\n";
}

int main(){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t; cin >> t;
    while(t--)
        solve();
}