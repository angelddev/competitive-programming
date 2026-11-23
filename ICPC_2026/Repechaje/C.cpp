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

ll n;
vpl adj[200009];
vpl adjrev[200009];
ll hijos[200005];
ll ans[200005];

ll dfs(ll node, ll parent, ll sum){
    ll temp = sum;
    
    if(node!=1)
        hijos[node]+=adj[node].size()-1;
    else 
        hijos[node]+=adj[node].size();

    for(pll v : adj[node]){
        if(v.F!=parent){
            ll tec = dfs(v.F, node, temp+v.S);
            sum+= tec;
            hijos[node]+=hijos[v.F];
        }
    }

    return sum;
}

void dfs2(ll node, ll parent, ll bw, ll fw){
    ans[node] = ans[parent] + bw * (n - hijos[node] - 1) - fw * (hijos[node] + 1);
    
    for(int i = 0; i < adj[node].size(); i++){
        if(adj[node][i].F == parent) continue;
        dfs2(adj[node][i].F, node, adjrev[node][i].S, adj[node][i].S);   
    }
}

void solve(){
    cin >> n;

    ll x, y, c, r;
    f(i,0,n-1){
        cin >> x >> y >> c >> r;
        adj[x].pb({y, c});
        adj[y].pb({x, r});
        adjrev[x].pb({y, r});
        adjrev[y].pb({x, c});
    }

    ans[1] = dfs(1, 0, 0);

    for(int i = 0; i < adj[1].size(); i++){
        dfs2(adj[1][i].F, 1, adjrev[1][i].S, adj[1][i].S);
    }

    cf(i,1,n){
        cout << ans[i] << " ";
    } cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; 
    while(t--){
        solve(); 
    }
}