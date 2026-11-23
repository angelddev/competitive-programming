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
vvll adj2;
vll vis;
ll top = -1;

void dfs(ll node){

    vis[node] = 1;
    
    for(ll v : adj[node]){
        if(!vis[v]){
            dfs(v);
        }
    }
    
}

void dfs2(ll node){

    vis[node] = 1;
    
    for(ll v : adj2[node]){
        if(!vis[v]){
            dfs2(v);
        }     
    }

}


void solve(){

    ll n, m; cin >> n >> m;

    adj.assign(n+1, vll());
    adj2.assign(n+1, vll());
    vis.assign(n+1, 0);

    ll x, y;
    f(i,0,m){
        cin >> x >> y;
        adj[x].pb(y);
        adj2[y].pb(x);
    }
    
    dfs(1);
    cf(i,1,n){
        if(!vis[i]){
            cout << "NO\n" << 1 << " " << i << "\n";
            return;
        }
    }


    cf(i,1,n){
        vis[i] = 0;
    }


    dfs2(1);
    cf(i,1,n){
        if(!vis[i]){
            cout << "NO\n" << i << " " << 1 << "\n";
            return;
        }
    }

    cout << "YES\n";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; //cin >> t;
    while(t--){
        solve(); 
    }
}

