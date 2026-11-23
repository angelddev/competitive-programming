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

vll dp;
vector<vpl> adj;
vll checked;

void dfs(ll node, ll parent, ll lst_idx){
    checked[node]=1;
    for(pll kid: adj[node]){
        if(kid.first==parent) continue;
        if(checked[kid.F]==0){
        if(lst_idx<kid.S){
            dp[kid.F]=dp[node];
        } else dp[kid.F]=dp[node]+1;
        dfs(kid.F, node, kid.S);
        }
    }
}   

void solve(){
    ll n; cin >> n;
    adj.assign(n+1, vpl()); 
    dp.assign(n+1, 0);
    checked.assign(n+1, 0);
    ll u, v;
    dp[1]=1;
    f(i,0,n-1){
        cin >> u >> v;
        adj[u].pb({v, i});
        adj[v].pb({u, i});
    }
    dfs(1, 0, -1);

    ll mx=0;
    cf(i,1,n){
        mx=max(dp[i], mx);
    }

    cout << mx << "\n";

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t; cin >> t;
    while(t--){
        solve();
    }
        
}


