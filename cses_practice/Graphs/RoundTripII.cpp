#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
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
vll parent;
ll flag=0, cycle_start, cycle_end;

void dfs(ll node){
    vector<pair<ll, ll>> stk;
    stk.pb({node, 0});
    visited[node] = 1;

    while(!stk.empty()){
        if(flag) return;
        
        ll u = stk.back().F;
        ll idx = stk.back().S;

        if(idx < adj[u].size()){
            ll v = adj[u][idx];
            stk.back().S++; 

            if(visited[v] == 1){
                flag = 1;
                cycle_start = v;
                cycle_end = u;
                return;
            } else if(visited[v] == 0){
                parent[v] = u;
                visited[v] = 1;
                stk.pb({v, 0});
            }
        } else {
            visited[u] = 2; 
            stk.pop_back();
        }
    }
}

void solve(){
    ll n, m; cin >> n >> m;
    adj.assign(n+1, vll());
    visited.assign(n+1, 0);
    parent.assign(n+1, -1);
    ll x, y;
    f(i,0,m){
        cin >> x >> y;
        adj[x].pb(y);
    }

    cf(i,1,n){
        if(flag) break;
        if(visited[i]==0){
            dfs(i);
        }
    }

    if(flag==0){
        cout << "IMPOSSIBLE\n"; return;
    }

    vll ans;
    ans.pb(cycle_start);
    ll r=cycle_end;
    while(r!=cycle_start){
        ans.pb(r);
        r=parent[r];
    }
    ans.pb(cycle_start);
    reverse(all(ans));

    cout << ans.size() << "\n";
    f(i,0,(ll)ans.size()){
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