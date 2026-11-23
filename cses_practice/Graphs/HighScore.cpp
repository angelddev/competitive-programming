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

vector<vector<ll>> adj;
vll visited;
struct Edge{
    ll a, b, weight;
};

void dfs(ll node){
    visited[node]=1;
    for(auto a: adj[node]){
        if(visited[a]==0)
        dfs(a);
    }
}


void solve(){

    ll n, m; cin >> n >> m;
    ll x, y, weight;
    vector<Edge> edges;
    f(i,0,m){
        cin >> x >> y >> weight;
        Edge e; e.a=x, e.b=y, e.weight=weight*-1;
        edges.pb(e);
    }
    vll distances(n+1, INF);
    distances[1]=0;
    
    f(i,0,n-1){
        for(Edge e : edges){
            if(distances[e.a]<INF){
                distances[e.b]=min(distances[e.b], distances[e.a]+e.weight);
            }
        }
    }
    

    adj.assign(n+1, vll());
    for (auto e : edges)
        adj[e.a].push_back(e.b);


    visited.assign(n+1, 0);
    vll bad;
    for(Edge e : edges){    
        if(distances[e.a]<INF){
            if(distances[e.b]>distances[e.a]+e.weight){
                bad.pb(e.b);
            }
        }
    }
    
    for(auto a : bad){
        if (visited[a]==0)
        dfs(a);
    }

    if(visited[n]==1){
        cout << -1 << "\n";
        return;
    }
    cout << distances[n]*-1 << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t=1; 
    while(t--){
        solve(); 
    }
}