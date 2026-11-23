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
 
map<ll, vll> adj;
map<ll, vll> adj2;
vll vis;
vector<char> ans;
stack<ll> st;
 
void dfs(ll node){
 
    vis[node] = 1;
    for(ll e : adj[node]){
        if(!vis[e]) dfs(e);
    }
 
    st.push(node);
 
}
 
void dfs2(ll node, ll grp){
 
    vis[node] = grp;
    
    for(ll e : adj2[node]){
        if(!vis[e]){
            dfs2(e, grp);
        }
    }
}
 
void solve(){
 
 
    ll n, m; cin >> n >> m;
    ans.assign(2*m+1, '.');
    vis.assign(3*m+5, 0);
 
    ll x, y;
    char sign1, sign2;
    f(i,0,n){
        cin >> sign1 >> x >> sign2 >> y;
 
        if(sign1=='-') x-=2*x;
        if(sign2=='-') y-=2*y;
        adj[-x+m].pb(y+m);
        adj[-y+m].pb(x+m); 
        adj2[y+m].pb(-x+m);
        adj2[x+m].pb(-y+m);
    }
 
    cf(i,-m,m){
        if(vis[i+m]==0&&i!=0){
            dfs(i+m);
        }
    }
 
    cf(i,0,3*m+2){
        vis[i] = 0;
    }
 
    ll grp = 1;
 
    while(!st.empty()){
        ll node = st.top();
        st.pop();
 
        if(vis[node]==0){
            dfs2(node, grp++);
        }
 
        
    }
 
    cf(i,1,m){
        if(vis[i+m]>vis[-i+m]) ans[i+m] = '+';
        else ans[i+m] = '-';
        if(vis[i+m]==vis[-i+m]){
            cout << "IMPOSSIBLE\n";
            return;
        }
    }
    cf(i,1,m){
        cout << ans[i+m] << " "; 
    } cout << "\n";
 
  
 
 
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
 
    ll t = 1; //cin >> t;
    while(t--){
        solve(); 
    }
}