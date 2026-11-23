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
vvll adj;
vll visited;
ll flag=0;
vll ans;

void dfs(ll node){

    if(flag) return;
    visited[node]=1;
    for(auto e: adj[node]){
        if(visited[e]==1){
            flag=1;
            return;
        }
        if(!visited[e]) dfs(e);
    }
    visited[node]=2;
    ans.pb(node);
}


void solve(){
    
    ll n, m;
    cin >> n >> m;
    adj.assign(n+1, vll());
    visited.assign(n+1, 0);
    ll a, b;
    f(i,0,m){
        cin >> a >> b;
        adj[a].pb(b);
    }

    cf(i,1,n){
        if(!visited[i]) dfs(i);
        if(flag) break;
    }

    if (flag){
        cout << "IMPOSSIBLE\n"; return;
    }

    reverse(all(ans));
    f(i,0,n){
        cout << ans[i] << " ";
    }
    cout << "\n";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t=1; 
    while(t--){
        solve(); 
    }
}