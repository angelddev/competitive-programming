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

vvll adj;
vector<vpl> tins;
ll timer;
vvll up;
vll depth;

void dfs(ll node, ll dep, ll parent){
    depth[node] = dep;
    up[node][0] = parent;

    for(int i = 1; i < LOG; i++)
        up[node][i] = up[ up[node][i-1] ][i-1];

    tins[dep].push_back({timer++, node});

    for(auto e : adj[node]){
        dfs(e, dep + 1, node);
    }
}

ll lca(ll u, ll v){

    if(depth[u]<depth[v]) swap(u, v);

    ll diff=depth[u]-depth[v];

    for(int i=LOG-1; i>=0; i--)
        if(diff&(1LL<<i))
            u=up[u][i];

    if(u==v) return u;

    for(int i=LOG-1; i>=0; i--){
        if(up[u][i]!=up[v][i]){
            u=up[u][i];
            v= up[v][i];
        }
    }

    return up[u][0];
}

void solve(){
    ll n; cin >> n;
    adj.assign(n+1, vll());
    tins.assign(n+2, vpl()); 
    timer = 0;

    ll x;
    cf(i, 2, n){
        cin >> x;   
        adj[x].push_back(i);
    }
    up.assign(n+1, vll(LOG));
    depth.assign(n+1, 0);       
    timer=0;

    dfs(1, 1, 1);

    f(i, 0, tins.size()){
        sort(all(tins[i]));
    }

    ll ans=n;

    f(i,0,tins.size()){
        set<int> seen;
        f(j,1,tins[i].size()){
            ll l = lca(tins[i][j-1].S, tins[i][j].S);
            if(seen.count(l)) continue;
            seen.insert(l); ans++;  
        }
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t; cin >> t;
    while(t--){
        solve(); 
    }
}