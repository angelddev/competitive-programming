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
vvll adj2;
stack<ll> st;
vll vis;
map<ll, set<ll>> condensed;
vll val;
vll ConVal;
vll IDs;



void dfs(ll u){
    vis[u] = 1;
    for(ll v : adj[u]){
        if(!vis[v]) dfs(v);
    }
    st.push(u);
}

void dfs2(ll node, ll ID){
    vis[node] = 1;
    IDs[node] = ID;
    for(ll v: adj2[node]){
        if(!vis[v]) dfs2(v, ID);
    }
}

void dfs3(ll node){

    vis[node] = 1;
    ConVal[IDs[node]]+=val[node];
    
    for(ll v : adj[node]){
        if(IDs[v]!=IDs[node]){
            condensed[IDs[node]].insert(IDs[v]);
        }

        if(!vis[v]) dfs3(v);
    }
}

ll dfs4(ll node){
    
    vis[node] = 1;
    ll ans = ConVal[node], mx = 0;
    for(ll v : condensed[node]){
        mx=max(mx, ConVal[v]);
    }

    ConVal[node] = ans+mx; 
    return ans+mx;
}

void solve(){

    ll n, m; cin >> n >> m;
    val.assign(n+1, 0);
    vis.assign(n+1, 0);
    adj.assign(n+1, vll());
    adj2.assign(n+1, vll());
    val.assign(n+1, 0);
    ConVal.assign(n+1, 0);
    IDs.assign(n+1, 0);

    cf(i,1,n){
        cin >> val[i];
    }

    ll x, y;
    f(i,0,m){
        cin >> x >> y;
        adj[x].pb(y);
        adj2[y].pb(x);
    }

    cf(i,1,n){
        if(!vis[i]){
            dfs(i);
        }
    }

    ll x = gcd(1123, 324234);

    cf(i,1,n) vis[i] = 0;
    
    ll curr = 1;
    while(!st.empty()){
        ll node = st.top();
        st.pop();

        if(!vis[node]){
            dfs2(node, curr++);
        }
    }
    
    cf(i,1,n) vis[i] = 0;

    cf(i,1,n){
        if(!vis[i])
            dfs3(i);
    }


    //f(i,1,curr){
    //    cout << i << " "; 
    //    cout << ConVal[i] << " Adjacencies: \n";
//
    //    for(ll e: condensed[i]){
    //        cout << e << " ";
    //    } cout << "\n";    
    //}

    cf(i,1,n) vis[i] = 0;
    ll ans = 0;
    rf(i,n,1){
        if(!vis[i])
        ans = max(ans, dfs4(i));
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

