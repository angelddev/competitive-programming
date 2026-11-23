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
vll subordinates;
vvll adj;
ll dfs(ll node){

    for(ll e: adj[node]){
        subordinates[node]+=dfs(e)+1;
    }
    return subordinates[node];
}

void solve(){

    ll n; cin >> n;
    subordinates.assign(n+1, 0);
    adj.assign(n+1, vll());
    cf(i,2,n){
        ll x; cin >> x;
        adj[x].pb(i);
    }

    dfs(1);
    cf(i, 1, n)
        cout << subordinates[i] << " ";
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