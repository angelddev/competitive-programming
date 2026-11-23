#include<bits/stdc++.h>
 
#define ll long long 
#define all(a) begin(a), end(a)
#define pll pair<ll, ll> 
#define vll vector<ll>
#define vvl vector<vll>
#define vpl vector<pll> 
#define f(i, s, e) for(ll i=s; i<e; i++)
#define cf(i, s, e) for(ll i=s; i<=e; i++)
#define rf(i, s, e) for(ll i=s; i>=e; i--) 
#define MOD(x) ((((x)%mod) + mod)%mod)
#define F first
#define S second
#define pb push_back 
using namespace std; 
typedef long double ld;
 
const ll INF = 1e18; 
const ll mod = 998244353;


void solve(){
    ll n, m; cin >> n >> m;
    vvl adj(n+1);
    f(i,0,m){
        ll u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vector<ll> color(n+1, -1);
    ll ans = 0;

    cf(i,1,n){
        if(color[i]==-1){
            ll bipartite=1;
            color[i]=0;
            ll cnt1=0, cnt0=1;
            queue<ll> bfs;
            bfs.push(i);
            while(!bfs.empty()){
                ll t=bfs.front();
                bfs.pop();
                for(ll neighbors: adj[t]){
                    if(color[neighbors]==-1){
                        if(color[t]==1){
                            color[neighbors]=0;
                            cnt0++;
                            bfs.push(neighbors);
                        } else {color[neighbors]=1; cnt1++; bfs.push(neighbors);}
                    }
                    else if(color[neighbors]!=(color[t]^1)){
                        bipartite=0;
                    }
                }
            }

            if(bipartite==1){
                ans+=max(cnt0, cnt1);
            }
        }
    }

    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    ll t; cin >> t;
    while(t--)
        solve();
}