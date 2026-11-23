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
vvll adj;
vll visited;
vll ans;

void dfs(ll node){
    
    for(ll e: adj[node]){
        if(visited[e]==0){
        visited[e]=1; 
        dfs(e);   
        }  
    }
    ans.pb(node);
}

void solve(){

    ll n, m; cin >> n >> m;
    adj.assign(n+1, vll());
    visited.assign(n+1, 0);
    ll a, b;

    f(i,0,m){
        cin >> a >> b;
        adj[a].pb(b);
    }
    visited[1]=1;
    dfs(1);

    reverse(all(ans));    
    vll ways(n+1, 0);
    ways[1]=1;
    f(i,0,ans.size()){
        for(ll e: adj[ans[i]]){
            ways[e]=(ways[e]+ways[ans[i]])%MOD;
        }
    }

    cout << ways[n]%MOD<< "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t=1; 
    while(t--){
        solve(); 
    }
}