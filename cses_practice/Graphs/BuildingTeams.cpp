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
vll checked;
vll colors;

void dfs(ll node){
    checked[node]=1;
    for(ll neighbors: adj[node]){
        if(checked[neighbors]==0){
            colors[neighbors]=colors[node]^1;
            dfs(neighbors);
        } else if(colors[neighbors]==colors[node]){
            colors[0]=2;
        }
    }
}

void solve(){
   
    adj.clear();
    checked.clear();
    colors.clear();

    ll n, m; cin >> n >> m;
    adj.resize(n+1, vll ());
    checked.resize(n+1, 0);
    colors.resize(n+1, 0);
    ll x, y;
    f(i,0,m){
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    colors[1]=1;
    cf(i,1,n){
        if(checked[i]==0){
            colors[i]=1;
            dfs(i);
        }
    }

    if(colors[0]==2){
        cout << "IMPOSSIBLE\n";
        return;
    }

    cf(i,1,n){
        cout << colors[i]+1 << " ";
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