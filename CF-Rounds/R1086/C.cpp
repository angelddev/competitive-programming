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
    vector<pair<ld, ld>> task(n);
    f(i,0,n){
        cin >> task[i].first >> task[i].second; 
    }

    vector<ld> dp(n+1);

    dp[n]=0;
    for(ll i=n-1; i>=0; i--){
        ld imag=1.0-task[i].second/100;
        dp[i]=max(dp[i+1], task[i].first+imag*dp[i+1]);
    }

    cout << fixed << setprecision(10) << dp[0] << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    ll t; cin >> t;
    while(t--)
        solve();
}