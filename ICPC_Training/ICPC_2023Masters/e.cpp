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

const ll INF = 1e9;
const ll MOD = 1e9 +7;


struct MaxFlow{
    static const ll INF = 1e18;

    struct Edge {
        int from; 
        int to;
        ll w;
};

int n, source, sink;
vector <vector<int>> g;
vector<Edge> edges;
vector<int> level;
vector<int> ptr;
ll flow = 0;

MaxFlow(int n, int source, int sink)
    : n(n), source(source), sink(sink), g(n), level(n), ptr(n) { }
int add_edge(int from, int to, ll foward, ll backward = 0){
    const int id = (int) edges.size();
    g[from].emplace_back(id);
    edges.pb({from, to, foward});
    g[to].emplace_back(id+1);
    edges.pb({to, from, backward});
    return id;
}

bool bfs(){
    level.assign(n,-1);
    queue<int> q;
    q.push(source);
    level[source] = 0;
    while(!q.empty()){
        int s = q.front();
        q.pop();
        for (int i : g[s]){
            auto &e = edges[i];
            if(level[e.to] == -1 && e.w > 0){
                level[e.to] = level[s] + 1;
                q.push(e.to);
            }
        }
    }
    return level[sink] != -1;
}

ll dfs(int node, ll flow){
    if(node == sink) return flow;
    for(int & it = ptr[node]; it < g[node].size(); ++it){
        int i= g[node][it];
        auto &e = edges[i];
        auto &back = edges[i ^ 1];
        if(e.w > 0 && level[e.to] == level[node] + 1){
            ll f= dfs(e.to, min(flow, e.w));
            if(f > 0){
                e.w -= f;
                back.w+= f;
                return f;
            }
        }
    }
    return 0;
}

ll max_flow(){
    while(bfs()){
       ptr.assign(n, 0);
       ll f;
       while (( f = dfs(source, INF)) > 0) flow += f; 
    }
    return flow;
}
};

ll vis[205];
vll adj[205];

void dfs(ll v){
    vis[v]=1; 
    for(auto u: adj[v]){
        if(vis[u]) continue;
        dfs(u);
    }
}

void solve(){
    ll n, m ,s , t, pr[205];
    cin >> n >> m >> s >> t;
    MaxFlow flow = MaxFlow(2*n+2, s, t); 
    cf(i, 1, n)adj[2*i-1].pb(2*i); 
    f(i, 0, m){
        ll a, b, w;
        cin>>a>>b>>w;
        flow.add_edge(2*a, 2*b-1, -w); 
        adj[2*a].pb(2*b-1); 
    }
    cf(i, 1, n){
        cin>>pr[i]; 
        flow.add_edge(2*i-1, 2*i, pr[i]);
    }
    dfs(s); 
    if(!vis[t]){
        cout<<"Bad Trip\n";
    }
    else if(0){
        //Otro
        cout<<"Money Hack\n";
    }
    else{
        cout<<flow.max_flow()<<"\n"; 
    }
    

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t=1; 
    while(t--){
        solve(); 
    }
}