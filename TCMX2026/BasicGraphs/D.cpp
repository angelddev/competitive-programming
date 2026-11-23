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
const int LOG = 30;

void solve(){

    ll n, m; cin >> n >> m;

    vvll adj(n+1, vll());
    ll x, y;

    f(i,0,m){
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    ll q; cin >> q;
    queue<ll> qu;
    vll vis(n+1);
    vll dis(n+1, INF);
    
    f(i,0,q){
        cin >> x;
        qu.push(x);
        dis[x]=0;
    }
    
    ll best = 0;
    while(!qu.empty()){
        ll node = qu.front();
        qu.pop();

        if(vis[node]==1) continue;
        vis[node]=1;

        for(ll v : adj[node]){
            if(!vis[v]){
                dis[v]=min(dis[node]+1, dis[v]);
                qu.push(v);
                best = max(dis[v], best);
            }
        }
    }


    vll bests;
    cf(i, 1, n){
        if(dis[i]==best){
            bests.pb(i);
        }
    }

    sort(all(bests));
    cout << bests.size() << "\n";

    for(ll i = 0; i < bests.size(); i++){
        cout << bests[i] << " ";
    } cout << "\n";
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; //cin >> t;
    while(t--){
        solve(); 
    }
}

