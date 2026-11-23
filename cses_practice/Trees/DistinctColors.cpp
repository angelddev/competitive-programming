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

vector<set<ll>> vec;
vll score;
vvll adj;

void dfs(ll node, ll parent){
    for(ll v: adj[node]){
        if(v== parent) continue;
        dfs(v, node);
        if(vec[v].size()>vec[node].size()) swap(vec[node], vec[v]);
        for(ll val: vec[v]){
            vec[node].insert(val);
        }
    }

    score[node] = vec[node].size(); 
}


void solve(){
 
    ll n; cin >> n;

    adj.assign(n+1, vll());
    score.assign(n+1, 0);
    vec.assign(n+1, set<ll>());
    ll x;
    cf(i,1,n){
        cin >> x;
        vec[i].insert(x);
    }

    ll y;
    cf(i,1,n-1){
        cin >> x >> y;

        adj[y].pb(x);
        adj[x].pb(y);
    }

    dfs(1, 0);

    cf(i,1,n){
        cout << score[i] << " ";
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

