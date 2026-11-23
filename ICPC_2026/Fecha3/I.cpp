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

map<ll, ll> val;
map<ll, vll> adj;
map<ll, ll> vis;

ll dfs(ll node){

    ll temp = val[node];
    vis[node] = 1;


    for(ll e : adj[node]){
        if(!vis[e])
            temp+=dfs(e);
    }

    return temp;

}

void solve(){

    ll m, n; cin >> m >> n;

    ll x, y;
    vll posiciones(n);
    f(i,0,n){
        cin >> x >> y;
        posiciones[i]=x;
        val[x] = y;
    }



    vector<pair<ll, pll>> dfsLeaders;
    char c;

    ll d;
    f(i,0,n){
        cin >> c;
        if(c=='A'){
            cin >> x >> y;
            dfsLeaders.pb({posiciones[i], {x, y}});
        } else if(c == 'D'){

        } else {
            cin >> d;
            adj[posiciones[i]].pb(d);
            adj[d].pb(posiciones[i]);
        }
    }

    vll valorLeader(n);

    vector<pair<ll, pll>> SweepLine;
    for(auto lead : dfsLeaders){
        ll v = dfs(lead.F);
        vis.clear();
        SweepLine.pb({lead.S.S+lead.S.F, {0, v}});
        SweepLine.pb({lead.S.F, {1, v}});
    }

    

    sort(all(SweepLine));

    ll cur = 0, ans = 0;
    for(auto event : SweepLine){
        if(event.S.F==0){
            cur-=event.S.S;
        } else {
            cur+=event.S.S;
        }

        ans = max(ans, cur);
    }

    cout << ans << "\n";
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; //cin >> t;
    while(t--){
        solve(); 
    }
}

