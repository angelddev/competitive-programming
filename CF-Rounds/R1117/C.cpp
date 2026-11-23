#include <bits/stdc++.h>

#define ll long long 
#define all(a) begin(a), end(a)
#define pll pair<ll, ll>
#define vll vector<ll>
#define vvll vector<vll>
#define vpl vector<pll>
#define f(i, s, e) for(ll i=s; i<e; i++)
#define cf(i, s, e) for(ll i=s; i<=e; i++)
#define rf(i, s, e) for(ll i=s; i>=e; i--)
#define F first
#define S second
#define pb push_back
using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9 +7;
const int LOG = 30;

vvll adj;
set<ll> ans;
ll lowest = INF;
ll banned = -1;

void dfs(ll node, ll depth){
    if(depth < lowest && ans.count(node) == 1){
        banned = node;
        lowest = depth;
    }
    for(ll v : adj[node]){
        dfs(v, depth+1);
    }    
}

void solve(){

    ll n, m; cin >> n;
    adj.assign(n+1, vll());
    ll x;

    cf(i,2,n){
        cin >> x;
        adj[x].pb(i); 
    }

    cin >> m;
    
    f(i,0,m){
        cin >> x;
        ans.insert(x);
    }

    dfs(1, 0);

    cout << m-1 << " ";
    //cout << banned << "\n";
    for(ll u : ans){
        if(banned == u) continue;
        cout << u << " ";
    } cout << "\n";
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; cin >> t;
    while(t--){
        solve(); 
        adj.clear();
        lowest = INF;
        banned = -1;
        ans.clear();
    }
}

