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
ll val[400000];
vll adj[400000];
vll values[200006];
ll sm[400000];
ll perf[5000009];
ll ans = 0;
ll n;

void isPerfect(){
    for(ll i = 1; i <= 2000; i++){
        perf[i*i] = 1;
    }
}

ll dfs(ll node, ll parent){
    
    for(ll v : adj[node]){
        if(v==parent) continue;
        ll temp = dfs(v, node);
        values[node].pb(temp);
        sm[node]+=temp;
    }

    sm[node]++;
    return sm[node];
}

void dfs2(ll node, ll parent){

    if(parent!=0){
        values[node].pb(sm[parent]-sm[node]);
        sm[node]+=sm[parent]-sm[node];
    }

    ll comb1 = ((n)*(n-1))/2;
    ll comb2 = ((n)*(n-1)*(n-2))/6;
    if(perf[val[node]]&&adj[node].size()>1){
        for(ll val : values[node]){
            comb1-=(val*(val-1))/2;
            comb2-=(((val)*(val-1)*(val-2))/6)+((val*(val-1))/2)*(n-val);
        }
        ans+=comb1+comb2;
    }


    for(ll v : adj[node]){
        if(v != parent)
        dfs2(v, node);
    }
}

void solve(){
 
    cin >> n;
    cf(i,1,n){
        cin >> val[i];
    }

    ll x, y;
    f(i,0,n-1){
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    dfs(1, 0);
    n--;    
    dfs2(1, 0);

    cout << ans << "\n";
    ans = 0;
    cf(i,1,n+1){
        adj[i].clear();
        values[i].clear();
        sm[i] = 0;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; cin >> t;
    isPerfect();
    while(t--){
        solve(); 
    }
}

