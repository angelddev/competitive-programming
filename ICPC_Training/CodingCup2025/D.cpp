#include <bits/stdc++.h>

#define ll long long
#define ld long double 
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

const double INF = 1e18;
const ll MOD = 1e9 +7;


void solve(){

    ll m; cin >> m;
    vector<vpl> adj(1000001);
    ll x, y;
    ll mx=1;
    f(i,0,m){
        cin >> x >> y;
        mx=max({mx, x, y});
        adj[x].pb({y, y});
    }

    vll p(1000001, -1);
    priority_queue<pair<ld,ll>, vector<pair<ld,ll>>, greater<pair<ld,ll>>> pq;
    pq.push({0, 1});
    vector<long double> distance(1000001, INF);
    distance[1]=0;
    while(!pq.empty()){
        auto [w, u] = pq.top();
        pq.pop();
        if(w>distance[u]) continue;
        for(auto e:adj[u]){
            ld wl=log(e.S);
            if(distance[u]+wl<distance[e.S]){
                distance[e.S] = distance[u] + wl;
                p[e.S] = u;
                pq.push({distance[e.S], e.S});
            }
        }
    }

    vll ans;
    ans.pb(mx);
    while(p[mx]!=1){
        ans.pb(p[mx]);
        mx=p[mx];
    }
    ans.pb(1);
    reverse(all(ans));
    f(i,0,ans.size()){
        cout << (ll)ans[i] << " ";
    } cout << "\n";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t=1; 
    while(t--){
        solve(); 
    }
}