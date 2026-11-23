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


void solve(){

    ll n, m; cin >> n >> m;
    vector<vpl> adj(n+1);

    f(i,0,m){
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].pb({c, b});
    }

    //minimum price
    vll distance(n+1, INF);
    distance[1]=0;

    priority_queue<pll, std::vector<pll>, std::greater<pll>> que;
    que.push({0, 1});
    vll mn(n+1, INF), mx(n+1, -INF), ways(n+1, 0);
    ways[1]=1;
    mn[1]=0;
    mx[1]=0;

    while(!que.empty()){
        
        ll w=que.top().F, nd=que.top().S;
        que.pop();
        if(w>distance[nd]) continue;

        for(pll e : adj[nd]){
            ll destiny=e.S, cost = e.F;
            if(w+cost<distance[destiny]){
                ways[destiny]=ways[nd];
                mn[destiny]=mn[nd]+1;
                mx[destiny]=mx[nd]+1;
                distance[destiny]=w+cost;
                que.push({w+cost, destiny});
            } else if(w+cost==distance[destiny]){
                ways[destiny]=(ways[destiny]+ways[nd])%MOD;
                mn[destiny]=min(mn[destiny], mn[nd]+1);
                mx[destiny]=max(mx[destiny], mx[nd]+1);
            }
        }
    }

    cout << distance[n] << " " << ways[n]%MOD << " " << mn[n] << " " << mx[n] << "\n";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t=1; 
    while(t--){
        solve(); 
    }
}