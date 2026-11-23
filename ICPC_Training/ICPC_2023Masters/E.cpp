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

const ll INF = 1e15;
const ll MOD = 1e9 +7;

ll t, n, m, k, a, b; 

struct Edge{
    ll a, b, cost;
};

vector<Edge> edges;
vll adj[105]; 
ll vis[105]; 

void dfs(ll v){
    vis[v]=1; 
    for(auto u: adj[v]){
        if(vis[u]) continue;
        dfs(u); 
    }
}

void solve(){

    ll n, m , s, t;
    cin >> n >> m >> s >> t;
    f(i,0,m){
        Edge e;
        ll costt, a, b;
        cin >> a >> b >> costt;
        e.a=a;
        e.b=b;
        e.cost=costt;
        edges.pb(e);
    } 
    vll costs(n+1);
    cf(i,1,n){
        cin >> costs[i];
    }
    vll d(n+1, INF);
    d[s]=0;
    ll x;


    f(i,0,n){
        x=-1;
        for(Edge e: edges)
            if(d[e.a]<INF)
                if(d[e.b]>d[e.a]+e.cost-costs[e.b]){
                    d[e.b]=d[e.a]+e.cost-costs[e.b];
                    if(i==n-1){
                        memset(vis, 0, sizeof(vis));
                        dfs(e.b);
                        if(vis[t]) x=e.b; 
                    }
                }
    }

    if(x!=-1){
        cout << "Money hack!\n";
        return;
    }

    if(d[t]>=INF){
        cout << "Bad trip\n";
        return;
    }

    cout << (d[t])*-1 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); 

    t=1; 
    while(t--){
        solve(); 
    }
}