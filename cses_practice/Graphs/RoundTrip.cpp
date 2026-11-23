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
vvl adj;
vll visited;
vll parents;
ll gotcha = -1;
ll ending = -1;

void dfs(ll node, ll parent){
    if(gotcha!=-1) return;
    for(ll neighbors : adj[node]){
        if(visited[neighbors]==1&&parent!=neighbors){
            gotcha=neighbors;
            ending=node;
            return;
        } else if(visited[neighbors]==0){
            parents[neighbors]=node;
            visited[neighbors]=1;
            dfs(neighbors, node);
            if(gotcha!=-1) return;
        }
    }
}


void solve(){

    ll n, e; cin >> n >> e;
    adj.assign(n+1, vll());
    visited.assign(n+1, 0);
    parents.assign(n+1, -1);

    ll x, y;
    f(i,0,e){
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    cf(i,1,n){
        if(visited[i]==0){
            visited[i]=1;
            dfs(i, 0);
            if (gotcha!=-1) break;
        }
    }

    if(gotcha==-1){
        cout << "IMPOSSIBLE\n";
        return;
    }

    vll ans;
    ans.pb(gotcha);
    while(true){
        ans.pb(ending);
        ending=parents[ending];
        if(ending==gotcha) break;
    }
    ans.pb(gotcha);

    cout << ans.size() << "\n";
    f(i,0,ans.size()){
        cout << ans[i] << " ";
    }
    cout << "\n";



}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    //ll t; cin >> t;
    //while(t--)
        solve();
}