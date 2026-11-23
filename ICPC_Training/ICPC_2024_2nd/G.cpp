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
ll mx;
ll cont;
ll n;

ll dfs(ll node, ll parent){


    ll a=1;
    for(ll e : adj[node]){
        if(e==parent) continue;
        a+=dfs(e, node);
    }
    if(a*(n-a)>mx){
        mx=a*(n-a);
        cont=1;
    } else if(a*(n-a)==mx){
        cont++;
    }

    return a;
}

void solve(){

    cin >> n;
    adj.assign(n+1, vll());
    ll x, y;
    f(i,0,n-1){
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    mx=0;
    dfs(1,0);

    if(mx==0){
        mx=n-1;
        cont=n-1;
    }
    cout << mx << " " << cont << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t=1; 
    while(t--){
        solve(); 
    }
}