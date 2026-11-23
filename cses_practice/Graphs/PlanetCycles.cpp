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

vll adj;
vll vis;
ll goal = -1;
vll boolCycle;
vll closestCycle;
vvll up;
ll curCycle=0;
vll depth;
vll sz;


void dfs(ll u){

    vis[u]=1;
    ll v = adj[u];
    up[u][0] = v;

    if(v==u){
        vis[u] = 2;
        boolCycle[u] = ++curCycle;
        sz[boolCycle[u]] = 1;
        return;
    }

    if(vis[v]==1){
        depth[u] = 0;
        goal = v;
        vis[u] = 2;
        boolCycle[u] = ++curCycle;
        sz[boolCycle[u]]++;
        return;
    } 

    if(vis[v]==0) dfs(v);
    if(goal!=-1){
        depth[u] = depth[v]+1;
        boolCycle[u] = boolCycle[v];
        sz[boolCycle[u]]++;
        if(goal==u){
            goal=-1;
        }
        vis[u] = 2;
        return;
    } 

    if(boolCycle[v]!=0) {
        closestCycle[u] = v;
        depth[u] = 0;
    }
    else{ closestCycle[u] = closestCycle[v];
        depth[u] = depth[v]+1;
    } 
    vis[u]=2;
}

void solve(){

    ll n; cin >> n;

    adj.assign(n+1, 0);
    vis.assign(n+1, 0);
    boolCycle.assign(n+1, 0);
    closestCycle.assign(n+1, 0);
    up.assign(n+1, vll(LOG, 0));
    depth.assign(n+1, 0);
    sz.assign(n+1, 0);

    ll x;
    f(i,0,n){
        cin >> adj[i+1];
    }
 
    cf(i,1,n){
        if(vis[i]==0){
            dfs(i);
        }
    }


    f(j,1,LOG){
        cf(i,1,n){
            up[i][j] = up[up[i][j-1]][j-1]; 
        }
    }
 
    cf(i,1,n){
        if(boolCycle[i]!=0){
            cout << sz[boolCycle[i]] << " ";
        } else cout << depth[i]+sz[boolCycle[closestCycle[i]]]+1 << " ";
    } cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; //cin >> t;
    while(t--){
        solve(); 
    }
}

