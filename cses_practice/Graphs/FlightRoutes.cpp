#include <bits/stdc++.h>

#define ll long long 
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

    ll n, m, k; cin >> n >> m >> k;

    vector<vpl> adj(n+1, vpl());

    ll x, y, weight;
    f(i,0,m){
        cin >> x >> y >> weight;

        adj[x].pb({y, weight});
    }


    vll dis(n+1, INF);
    priority_queue<pll, vpl, greater<pll>> pq;
    dis[1] = 0;
    pq.push({0, 1});

    vll vis(n+1, 0);
    vll ans;
    while(!pq.empty()){
        ll u = pq.top().S;
        ll w = pq.top().F;
        pq.pop();

        if(vis[u] == k) continue;
        else vis[u]++;

        if(u == n){
            ans.pb(w);
        }

        for(pll v: adj[u]){
            pq.push({w+v.S, v.F});
        }
    }

    sort(all(ans));

    f(i,0,k){
        cout << ans[i] << " ";
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

