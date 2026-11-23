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
vll distance1;
vll distance2;

pll dfs(ll node, ll parent){

    ll h=0, no=node;
    for(ll e: adj[node]){
        if(e==parent) continue;
        pll as = dfs(e, node);
        if(as.F>h){
            h=as.F;
            no=as.S;
        }
    }

    return {h+1, no};
}

void dfs1(ll node, ll parent){

    for(ll e : adj[node]){
        if(e==parent) continue;
        distance1[e]=distance1[node]+1;
        dfs1(e, node);
    }

}

void dfs2(ll node, ll parent){

    for(ll e : adj[node]){
        if(e==parent) continue;
        distance2[e]=distance2[node]+1;
        dfs2(e, node);
    }

}

void solve(){

    ll n; cin >> n;

    adj.assign(n+1, vll());
    ll x, y;
    f(i,1,n){
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    ll node1 = dfs(1, 0).S;
    ll node2 = dfs(node1, 0).S;

    distance1.assign(n+1, 0);
    distance2.assign(n+1, 0);
    
    dfs1(node1, 0);
    dfs2(node2, 0);
    
    cf(i,1,n){
        cout << max(distance1[i], distance2[i])<< " ";
    }
    cout << "\n";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t=1; 
    while(t--){
        solve(); 
    }
}