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

    vector<vpl> adj(n+1, vpl());
    ll x, y, weight;
    f(i,0,m){
        cin >> x >> y >> weight;
        adj[x].pb({weight, y});
        adj[y].pb({weight, x});
    }

    vll visited(n+1);
    vll distances(n+1, INF);
    distances[1]=0;
    priority_queue<pll, std::vector<pll>, std::greater<pll>> cities;
    cities.push({0, 1});

    vll parents(n+1);
    parents[1]=-1;
    while(!cities.empty()){
        auto fr = cities.top();
        cities.pop();
        ll w=fr.F, c=fr.S;
        
        if(w>distances[c])continue;
        visited[c]=1;
        for(auto edge : adj[c]){
            if(visited[edge.S]==1)continue;
            if(w+edge.F<distances[edge.S]){
                parents[edge.S]=c;
                distances[edge.S]=w+edge.F;
                cities.push({distances[edge.S], edge.S});
            }
        }
    }


    if(distances[n]>=INF){
        cout << "-1\n";
        return;
    }
    vll ans;
    ll k=n;
    while(parents[n]!=-1){
        ans.pb(parents[n]);
        n=parents[n];
    }
    reverse(all(ans));
    ans.pb(k);


    f(i,0,ans.size()){
        cout << ans[i] << " ";
    }cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t=1; 
    while(t--){
        solve(); 
    }
}