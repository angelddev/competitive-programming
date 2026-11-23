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
vll sorted;
vll p;

void dfs(ll node){
    visited[node]=1;
    for(ll neighbor: adj[node]){
        if(!visited[neighbor]) {
            p[neighbor]=node;
            dfs(neighbor);
        }
    }   
    sorted.pb(node);
}

void solve(){

    ll n, m; cin >> n >> m;
    adj.assign(n+1, vll());
    visited.assign(n+1, 0);    
    p.assign(n+1, 0);
    ll x, y;
    f(i,0,m){
        cin >> x >> y;
        adj[x].pb(y);
    }

    dfs(1);
    reverse(all(sorted));
    vll distance(n+1, 0);
    vll ans;

    f(i,0,sorted.size()){
        ll node=sorted[i];
        for(ll e: adj[node]){
            if(distance[node]+1>distance[e]){
                p[e]=node;
                distance[e]=distance[node]+1;
            }
        }
    }

    if(distance[n]!=0){
        cout << distance[n]+1 << "\n";
        while(n!=1){
            ans.pb(n);
            n=p[n];
        } ans.pb(1);
        reverse(all(ans));
        for(ll i: ans){
            cout << i << " ";
        } cout << "\n";
    }
    
    else cout << "IMPOSSIBLE\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t=1; 
    while(t--){
        solve(); 
    }
}