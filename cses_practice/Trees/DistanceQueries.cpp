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

vvll adj;
vvll up;
vll depth;

void dfs(ll u, ll parent){
    
    depth[u] = depth[parent]+1;
    for(ll v: adj[u]){
        if(v!=parent){
            up[v][0] = u;
            dfs(v, u);
        } 
    }
}

ll get_dis(ll a, ll b){

    if(depth[a]<depth[b]) swap(a, b);

    
    ll k = depth[a]-depth[b];
    f(i,0,LOG){
        if(k&(1<<i)){
            a = up[a][i]; 
        }
    }
    ll ans = k;

    if(a==b){
        return ans;
    }

    ll dis = 0;
    rf(i,LOG-1,0){
        if(up[a][i]==up[b][i]) continue;
        else {
            dis+=(1<<i);
            a = up[a][i], b = up[b][i];
        }
    }

    return(ans+((dis+1)*2));
}

void solve(){
    
    ll n, q; cin >> n >> q;

    up.assign(n+1, vll(LOG));
    depth.assign(n+1, 0);
    adj.assign(n+1, vll());

    ll x, y;
    f(i,0,n-1){
        cin >> x >> y;

        adj[x].pb(y);
        adj[y].pb(x);
    }

    depth[1]=-1;
    up[1][0] = 1;
    dfs(1, 1);

    f(j, 1, LOG){
        cf(i,1,n){
            up[i][j] = up[up[i][j-1]][j-1]; 
        }
    }


    f(i,0,q){
        cin >> x >> y;
        cout << get_dis(x, y) << "\n";
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

