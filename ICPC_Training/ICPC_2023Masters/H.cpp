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

const ll INF = 1e9;
const ll MOD = 1e9 +7;


vvll adj;
set<pll> bridges;
vll visited;
vll tin, low;
ll timer;
ll n;
vll ids;
void IS_BRIDGE(int v,int to){
    bridges.insert({v, to});bridges.insert({to, v});
}

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    bool parent_skipped = false;
    for (int to : adj[v]) {
        if (to == p && !parent_skipped) {
            parent_skipped = true;
            continue;
        }
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                IS_BRIDGE(v, to);
        }
    }
}

void find_bridges() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}


void dfs1(ll node, ll id){

    visited[node]=1;
    ids[node]=id;
    for(auto u : adj[node]){
        if(visited[u]==0){
            if(!bridges.count({u, node})){
                dfs1(u, id);
            }
        } 
    }

}

void solve(){

    ll m;
    cin >> n >> m;

    adj.assign(n, vll());
    ids.assign(n, -1);
    ll x, y;
    f(i,0,m){
        cin >> x >> y;
        adj[--x].pb(--y);
        adj[y].pb(x);
    }

    find_bridges();

    fill(all(visited), 0);
    ll id=1;
    f(i,0,n){
        if(visited[i]==0){
            visited[i]=1;
            ids[i]=id;
            dfs1(i, id);
            id++;
        }
    }

    vll degree(n+1, 0);
    for(auto u:bridges){
    if(u.first < u.second){ 
        if(ids[u.first] != ids[u.second]){
            degree[ids[u.first]]++;
            degree[ids[u.second]]++;
        }
    }
}

    if(id-1==1){
        cout << 0 << "\n";
        return;
    }
    ll leaves=0;
    f(i, 1, id) { 
    if (degree[i]==1) leaves++; 
    if(degree[i]==0) leaves+=2;
    }

    cout << (leaves+1)/2 << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

 
    
        solve(); 
    
}