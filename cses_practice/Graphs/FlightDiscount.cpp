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
    vector<vector<pair<pll, ll>>> adj(n+1, vector<pair<pll, ll>>());
    ll x, y, weight;
    f(i,0,m){
        cin >> x >> y >> weight;
        adj[x].pb({{weight, y}, 0});
    }

    vvll visited(n+1, vll(2, 0));
    vvll distance(n+1, vll(2, INF));
    priority_queue<pair<pll, ll>, std::vector<pair<pll, ll>>, std::greater<pair<pll, ll>>> cities;

    cities.push({{0, 1}, 0});
    distance[1][0] = 0;
    while(!cities.empty()){
        ll d = cities.top().F.F;
        ll c = cities.top().F.S;
        ll state=cities.top().S;
        cities.pop();
        if(d>distance[c][state]) continue;
        visited[c][state]=1;
        for(auto a : adj[c]){
            if(state==1){
                if(visited[a.F.S][1]==1)continue;
                if(a.F.F+d<distance[a.F.S][1]){
                    distance[a.F.S][1]=a.F.F+d;
                    cities.push({{a.F.F+d, a.F.S},1});
                }
            } else {
                if(visited[a.F.S][0]==1)continue;
                //use
                if(a.F.F/2+d<distance[a.F.S][1]){
                    distance[a.F.S][1]=a.F.F/2+d;
                    cities.push({{a.F.F/2+d, a.F.S},1});
                }
                //ignore
                if(a.F.F+d<distance[a.F.S][0]){
                    distance[a.F.S][0]=a.F.F+d;
                    cities.push({{a.F.F+d, a.F.S},0});
                }
            } 
        }
    }


    cout << distance[n][1] << "\n";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t=1; 
    while(t--){
        solve(); 
    }
}