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

vector<vpl> adj;
vll sz;
vll prnt; 
vll vis;
vll wt;
vll parent;
vll depth;
vvll up;
vvll mn_wt;

struct edge{
    ll weight, a, b;
};


bool ord(edge e1, edge e2){
    return e1.weight < e2.weight;
}


int find_set(int v) {
    if (v == prnt[v])
        return v;
    return prnt[v] = find_set(prnt[v]);
}

void make_set(int v) {
    prnt[v] = v;
    sz[v] = 1;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
        prnt[b] = a;
        sz[a] += sz[b];
    }
}


void dfs(ll u){
    vis[u] = 1;

    for(auto [v, w] : adj[u]){
        if(!vis[v]){
            parent[v]=u;
            wt[v]=w;
            depth[v]=depth[u]+1;
            dfs(v);
        }
    }
}

vll nodes;

ll get_mn(ll a, ll b){
    ll ans = INF;    
    if(depth[a] < depth[b]){
        swap(a, b);
    }

    ll k = depth[a] - depth[b];

    for(ll i = 0; i < LOG; i++){
        if(k & (1LL << i)){ 
            ans = min(ans, mn_wt[a][i]);
            a = up[a][i];
        }
    }

    if(a == b){
        return ans;
    }
    for(ll i = LOG - 1; i >= 0; i--){
        if(up[a][i] != up[b][i]){
            ans = min({ans, mn_wt[a][i], mn_wt[b][i]});
            a = up[a][i];
            b = up[b][i];
        }
    }

    ans = min({ans, mn_wt[a][0], mn_wt[b][0]});

    return ans;
}

void dfs2(ll u, ll goal){
    if(u == goal){
        nodes.pb(goal);
        return;
    }
    vis[u] = 1;

    for(auto [v, w] : adj[u]){
        if(!vis[v]){
            dfs2(v, goal);
        }
        if(!nodes.empty()){
            nodes.pb(u);
            return;
        }
    }
}

void solve(){
    nodes.clear();
    ll n, m; cin >> n >> m;

    depth.assign(n+1, 0);
    parent.assign(n+1, 0);
    sz.assign(n+1, 1);
    prnt.assign(n+1, 0);
    vis.assign(n+1, 0);
    wt.assign(n+1, 0);
    up.assign(n+1, vll(LOG, 0));
    mn_wt.assign(n+1, vll(LOG, 0));

    ll x, y, w;
    vector<edge> edges;
    f(i,0,m){
        cin >> x >> y >> w;
        edge e;
        e.weight = w, e.a=x, e.b=y;
        edges.pb(e);
    }

    sort(all(edges), ord);

    cf(i,1,n){
        make_set(i);  
    }

    adj.assign(n+1, vpl());
    vpl cycles;
    f(i,0,m){
        if(find_set(edges[i].a)!=find_set(edges[i].b)){
            union_sets(edges[i].a,edges[i].b);
            adj[edges[i].a].pb({edges[i].b, edges[i].weight}); 
            adj[edges[i].b].pb({edges[i].a, edges[i].weight});
        } else {
            cycles.pb({edges[i].a, edges[i].b});
        }
    }

    cf(i,1,n){
        if(!vis[i]){
            dfs(i);
            parent[i]=i;
        }
            
    }

    cf(i,1,n){
        up[i][0] = parent[i];
        mn_wt[i][0] = wt[i];
    }

    for(ll j = 1; j<LOG; j++){
        for(ll i = 1; i <=n; i++){
            up[i][j] = up[up[i][j-1]][j-1];
            mn_wt[i][j] = min(mn_wt[i][j-1], mn_wt[up[i][j-1]][j-1]);
        }
    }


    ll best = INF, a, b;
    for(pll e : cycles){
        ll temp = get_mn(e.F, e.S);   
        if(temp<best){
            best = temp;
            a = e.F, b = e.S; 
        }
    }


    fill(all(vis), 0);
    dfs2(a, b);

    cout << best << " " << nodes.size() << "\n";
    for(ll nd : nodes){
        cout << nd << " ";
    } cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; cin >> t;
    while(t--){
        solve(); 
    }
}

