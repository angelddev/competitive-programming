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
 
vvl adj;
vll checked;
void dfs(ll i){
    checked[i]=1;
    for(ll neighbor : adj[i]){
        if(checked[neighbor]==0){
            dfs(neighbor);
        }
    }
}
void solve(){
   
    ll n, m; cin >> n >> m;
    adj.assign(n + 1, vll());
    checked.assign(n + 1, 0);
    ll c1, c2;
    f(i,0,m){
        cin >> c1 >> c2;
        adj[c1].pb(c2);
        adj[c2].pb(c1);
    }

    vll reps;
    cf(i,1,n){
        if(checked[i]==0){
            reps.pb(i);
            dfs(i);
        }
    }

    cout << reps.size()-1 << "\n";
    f(i,1,reps.size()){
        cout << reps[0] << " " << reps[i] << "\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    //ll t; cin >> t;
    //while(t--)
        solve();
}