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
vll parent;
vll sz;
vll depth;
ll lg;
vvll up;
vector<vpl> best;

struct AdjEdge {
    ll v, w, id;
};
vector<vector<AdjEdge>> adj;

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

struct Edge{
    ll n1, n2, u, c, ID;
};

bool EdgeSort(Edge e1, Edge e2){
    return e1.u<e2.u;
}

void binary_lifting(ll node, ll parent, ll weight_to_parent, ll id_to_parent) {
    up[node][0] = parent;
    best[node][0] = {weight_to_parent, id_to_parent};

    for (int i = 1; i < lg; i++) {
        up[node][i] = up[ up[node][i-1] ][i-1];
        if (best[node][i-1].F >= best[ up[node][i-1] ][i-1].F) {
            best[node][i] = best[node][i-1];
        } else {
            best[node][i] = best[ up[node][i-1] ][i-1];
        }
    }
    for (auto edge : adj[node]) {
        if (edge.v == parent) continue;
        
        depth[edge.v] = depth[node] + 1;
        binary_lifting(edge.v, node, edge.w, edge.id);
    }
}

pll get_max(ll a, ll b) {
    if (depth[b] > depth[a]) swap(a, b);

    pll mx_info = {-1, -1};
    for (int i = lg - 1; i >= 0; i--) {
        if (depth[a] - (1 << i) >= depth[b]) {
            if(best[a][i].F > mx_info.F){
                mx_info = best[a][i];
            }
            a = up[a][i];
        }
    }

    if (a == b) return mx_info;

    for (int i = lg - 1; i >= 0; i--) {
        if (up[a][i] != up[b][i]) {
            if(best[a][i].F > mx_info.F) mx_info = best[a][i];
            if(best[b][i].F > mx_info.F) mx_info = best[b][i];
            a = up[a][i];
            b = up[b][i];
        }
    }
    if(best[a][0].F > mx_info.F) mx_info = best[a][0];
    if(best[b][0].F > mx_info.F) mx_info = best[b][0];

    return mx_info;
}

void solve(){
    ll n, m;
    cin >> n >> m;
    parent.assign(n+1, 0);
    sz.assign(n+1, 0);
    depth.assign(n+1, 0);
    lg = ceil(log2(n)) + 1;
    up.assign(n+1, vll(lg));
    adj.assign(n+1, vector<AdjEdge>());
    best.assign(n+1, vpl(lg, {0, 0}));

    cf(i,1,n) make_set(i);
    vector<Edge> info;
    ll x;
    cf(i,1,m){
        cin >> x;
        Edge h;
        h.n1=h.c=h.n2=0;
        h.ID=i; h.u=x;
        info.pb(h);
    }
    cf(i,1,m){
        cin >> x;
        info[i-1].c=x;
    }

    ll  y;
    cf(i,1,m){
        cin >> x >> y;
        info[i-1].n1=x; info[i-1].n2=y;
    }

    ll budget;
    cin >> budget;

    sort(all(info), EdgeSort);
    
    vll msgIDs(m+1, 0);
    ll msgW=0;
    for(Edge e : info){
        if(find_set(e.n1) != find_set(e.n2)) {
            union_sets(e.n1, e.n2);
            msgW += e.u;
            msgIDs[e.ID] = 1;
            adj[e.n1].pb({e.n2, e.u, e.ID});
            adj[e.n2].pb({e.n1, e.u, e.ID});
        }
    }
    depth[1]=1;
    binary_lifting(1, 0, 0, 0);

    ll mn=msgW;
    ll bannedID=-1, newID=-1;
    for(Edge e: info){
        if(msgIDs[e.ID]==1){
            if(msgW-(budget/e.c)<mn){
                mn=msgW-(budget/e.c);
                newID=e.ID;
                bannedID=-1;
            }
        }
        else {
            pll temp= get_max(e.n1, e.n2);
            if(msgW-(temp.F)+(e.u)-(budget/e.c)<mn){
                mn=msgW-(temp.F)+(e.u)-(budget/e.c);
                newID=e.ID;
                bannedID=temp.S;
            }
        }
    }

    ll ans=0;

    for(auto e : info){
        if(e.ID==newID){
            ans+=(e.u)-(budget/e.c);
            continue;
        } 
        if(e.ID==bannedID) continue;
        else if(msgIDs[e.ID]==1){
            ans+=e.u;
        }
    }
    cout << ans << "\n";

    for(auto e : info){
        if(e.ID==newID){
            cout << e.ID << " " << (e.u)-(budget/e.c) << "\n";
            continue;
        }
        if(e.ID==bannedID) continue;
        else if(msgIDs[e.ID]==1){
            cout << e.ID << " " << e.u << "\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t=1;
    while(t--){
        solve(); 
    }
}