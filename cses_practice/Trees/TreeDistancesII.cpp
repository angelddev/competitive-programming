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
vll subsize;
vll heights;
vll distances;
ll n;


ll dfs(ll node, ll parent){

    for(ll e: adj[node]){
        if(e==parent) continue;
        subsize[node]+=dfs(e, node);
    }

    subsize[node]++;
    return subsize[node];

}

void dfs1(ll node, ll parent){

    for(ll e : adj[node]){
        if(e==parent) continue;
        heights[e]=heights[node]+1;
        dfs1(e, node);
    }

}

void dfs2(ll node, ll parent){

    for(ll e: adj[node]){
        if(e==parent) continue;
        distances[e] = (distances[node]-subsize[e])+(n-subsize[e]);
        dfs2(e, node);
    }

}

void solve(){

    cin >> n;
    adj.assign(n+1, vll());
    subsize.assign(n+1, 0);
    heights.assign(n+1, 0);
    distances.assign(n+1, 0);

    ll x, y;
    f(i,1,n){
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    dfs(1, 0);
    dfs1(1, 0);


    cf(i, 1, n){
        distances[1]+=heights[i];
    }

    dfs2(1, 0);
    cf(i, 1, n){
        cout << distances[i] << " ";
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