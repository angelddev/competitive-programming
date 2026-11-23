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

ll n, m;
ll cap[504][504];
set<ll> adj[504];

ll bfs(ll s, ll t, vector<ll> &parent){

    fill(all(parent), -1);

    parent[s]=-2;
    queue<pll> bfs;
    bfs.push({s, INF});

    while(!bfs.empty()){
        ll node = bfs.front().F;
        ll flow = bfs.front().S;
        bfs.pop();

        for(ll e : adj[node]){
            if(parent[e]==-1 && cap[node][e]!=0){
                parent[e] = node;
                ll new_flow = min(flow, cap[node][e]);
                if(e == t){
                    return new_flow;
                }
                bfs.push({e, new_flow});
            }
        }
    }
    return 0;
}

ll max_flow(ll s, ll t){

    ll flow = 0;
    vector<ll> parent(505);
    ll new_flow = 0;


    while(new_flow = bfs(s, t, parent)){

        flow+=new_flow;
        ll cur = t;

        //cout << "AUGMENTING PATH FOUND: \n";
        while(cur!=s){   
            ll prev = parent[cur];
            //cout << cur << " ";
            cap[prev][cur] -= new_flow;
            cap[cur][prev] += new_flow;
            cur = prev; 
        }
        //cout << "\n";
        

    }

    return flow;
}

void solve(){

    cin >> n >> m;
    ll x, y, c;
    f(i,0,m){
        cin >> x >> y >> c;
        adj[x].insert(y);
        adj[y].insert(x);
        cap[x][y] += c;
    }

    cout << max_flow(1, n) << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; //cin >> t;
    while(t--){
        solve(); 
    }
}

