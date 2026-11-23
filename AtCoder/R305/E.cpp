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
    
    ll x, y;
    vvll adj(n+1, vll());
    f(i,0,m){
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    priority_queue<pll> bfs;

    vll vals(n+1, -1);
    f(i,0,k){
        cin >> x >> y;
        bfs.push({y, x});   
        vals[x] = y;
    }

    while(!bfs.empty()){
        ll node = bfs.top().S;
        ll dis = bfs.top().F;
        bfs.pop();
        if(vals[node]>dis){
            continue;
        }

        for(ll e: adj[node]){
            if(vals[e]<dis-1){
                vals[e] = dis-1;
                bfs.push({dis-1, e});
            }
        }
    }


    ll cont = 0;
    cf(i,1,n){
        if(vals[i]>-1){
            cont++;
        }
    }

    cout << cont << "\n";
    cf(i,1,n){
        if(vals[i]>-1){
            cout << i << "\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; //cin >> t;
    while(t--){
        solve(); 
    }
}

