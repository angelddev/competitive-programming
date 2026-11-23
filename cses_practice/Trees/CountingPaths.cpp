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
vll start, fin;
vvll adj, up;
vll arr;
ll cont = 1;
vll depth;

ll get_lca(ll a, ll b){

    if(a==b) return a;
    if(depth[a]>depth[b]) swap(a, b);

    ll k = depth[b]-depth[a];
    for(int i = 0; i<LOG; i++){
        if(k&(1<<i)){
            b = up[b][i];
        }
    }

    if(a==b) return a;
    for(int i = LOG-1; i>=0; i--){
        if(up[a][i]==up[b][i]) continue;

        a = up[a][i];
        b = up[b][i];
    }

    return up[a][0];

}

void dfs(ll node, ll parent){

    depth[node] = depth[parent]+1;
    start[node] = cont++;
    up[node][0] = parent;

    for(ll v: adj[node]){
        if(v==parent) continue;
        dfs(v, node);
    }

    fin[node] = cont++;
}

void dfs2(ll node, ll parent){

    for(ll v: adj[node]){
        if(v==parent) continue;
        dfs2(v, node);
        arr[node]+=arr[v];
    }

}

void solve(){
 
    ll n, m; cin >> n >> m;

    depth.assign(n+1, 0);
    adj.assign(n+1, vll());
    up.assign(n+1, vll(LOG+1));
    arr.assign(2*n+4, 0);
    start.assign(n+1, 0);
    fin.assign(n+1, 0);
    ll x, y;
    f(i,0,n-1){
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    depth[0] = 0;
    dfs(1, 0);

    for(ll i = 1; i <= LOG; i++){
        for(ll j = 1; j <= n; j++){
            up[j][i] = up[up[j][i-1]][i-1];
        }
    }

    f(i,0,m){
        cin >> x >> y;
        ll dad = get_lca(x, y);
        //cout << dad << "\n";
        arr[x]++;
        arr[y]++;
        arr[dad]--;
        arr[up[dad][0]]--;
    }

    dfs2(1,0);

    cf(i,1,n){
       cout << arr[i] << " "; 
       // cout << arr[fin[i]] << " ";
    }

    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; //cin >> t;
    while(t--){
        solve(); 
    }
}

