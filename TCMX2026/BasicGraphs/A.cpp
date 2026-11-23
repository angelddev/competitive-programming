#include <bits/stdc++.h>

#define ll long long 
#define endl '\n'
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

ll a, b;
vll vis;
vvll adj;

ll dfs(ll u, ll goal){

    if(u==goal) return 1;
    vis[u]=1;
    for(ll v : adj[u]){
        if(!vis[v]){
            if(dfs(v, goal)==1) return 1;
        }
    }
    return 0;
}


void solve(){

    ll n, m; cin >> n >> m;

    vis.assign(n+1, 0);
    adj.assign(n+1, vll());

    cin >> a >> b;
    ll x, y;
    f(i,0,m){
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
     
    ll band = dfs(a, b);
    if(band) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; //cin >> t;
    while(t--){
        solve(); 
    }
}

