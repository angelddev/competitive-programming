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

vll a;
vvll adj;
vector<bool> vis;
multiset<ll> req, avail;

void dfs(ll u){
    vis[u]=true;
    auto it1=avail.find(u);
    if(it1!=avail.end()) avail.erase(it1);
    else req.insert(u);
    
    auto it2=req.find(a[u]);
    if(it2!=req.end()) req.erase(it2);
    else avail.insert(a[u]);

    for(ll v:adj[u]){
        if(!vis[v]) dfs(v);
    }
}

void solve(){
    ll n,x,y; cin>>n>>x>>y;
    
    a.clear(); a.resize(n+1);
    adj.clear(); adj.resize(n+1);
    vis.clear(); vis.resize(n+1,false);

    cf(i,1,n) cin>>a[i];

    cf(i,1,n){
        if(i+x<=n){ 
            adj[i].pb(i+x); adj[i+x].pb(i); 
        }
        if(i+y<=n){ 
            adj[i].pb(i+y); adj[i+y].pb(i); 
        }
    }

    cf(i,1,n){
        if(!vis[i]){
            req.clear(); avail.clear();
            dfs(i);
            if(!req.empty()||!avail.empty()){
                cout<<"NO\n";
                return;
            }
        }
    }
    cout<<"YES\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    ll t; cin>>t;
    while(t--){ solve(); }
}