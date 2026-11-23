#include<bits/stdc++.h>
 
#define ll long long 
#define all(a) begin(a), end(a)
#define pll pair<ll, ll> 
#define vll vector<ll>
#define vvl vector<vll>
#define vpl vector<pll> 
#define f(i, s, e) for(ll i=s; i<e; i++)
#define cf(i, s, e) for(ll i=s; i<=e; i++)
#define rf(i, s, e) for(ll i=s; i<e; i--)
#define MOD(x) ((((x)%mod) + mod)%mod)
#define F first
#define S second
#define pb push_back 
using namespace std; 
typedef long double ld;
 
const ll INF = 1e18; 
const ll mod = 1e9 + 7;
 
ll t, n, m, k, a, b, tot; 

void solve(){
    
    ll n, x; cin >> n >> x;
    vll coins(n);
    f(i,0,n) cin >> coins[i];
    sort(coins.begin(), coins.end());

    vll dp(x+1, 0);
    cf(i,1,x){
        f(j,0,n){
            if(coins[j]==i){
                dp[i]++;
                continue;
            }
            if(i<coins[j]||dp[i-coins[j]]==0) continue;
            dp[i]+=MOD(dp[i-coins[j]]);
        }
    }
    cout << MOD(dp[x]) << "\n";
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}