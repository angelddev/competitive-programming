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
ll best[200005][2];

void dfs(ll node, ll parent){

    if(adj[node].empty()){
        best[node][1]=0;
        best[node][0]=0;
        return;
    }
    for(ll e : adj[node]){
        if(e==parent) continue;
        dfs(e, node);
        best[node][0]+=max(best[e][1], best[e][0]);
    }
    best[node][1] = 0;

    for(ll e: adj[node]){
        if(e==parent) continue;
        ll curr = 1+best[e][0]+(best[node][0]-max(best[e][1], best[e][0]));
        best[node][1]=max(best[node][1], curr);
    }

}

void solve(){

    ll n; cin >> n;

    adj.assign(n+1, vll());
    f(i,1,n){
        ll x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    dfs(1, 0);

    cout << max(best[1][1], best[1][0]) << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t=1; 
    while(t--){
        solve(); 
    }
}