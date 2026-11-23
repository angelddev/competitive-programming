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
pll dist1={0,1};
ll heights[200005];


void dfs(ll node, ll parent){

    heights[node]=heights[parent]+1;
    for(ll e : adj[node]){
        if(e==parent) continue;
        dfs(e, node);
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

    heights[0]=-1;
    dfs(1, 0);
    ll mxnode=1, mx=0;
    f(i,0,200005){
        if(heights[i]>mx){
            mx=heights[i];
            mxnode=i;
        }
    }

    mx=0;
    memset(heights, 0, sizeof(heights));
    heights[0]=-1;
    dfs(mxnode, 0);
    f(i,0,200005){
        if(heights[i]>mx){
            mx=heights[i];
        }
    }

    cout << mx << "\n";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t=1; 
    while(t--){
        solve(); 
    }
}