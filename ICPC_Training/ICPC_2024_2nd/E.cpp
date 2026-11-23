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
const int LOG = 30;

void solve(){

    ll n; cin >> n;
    vvll adj(n+1);
    vpl nodes(n+1);
    cf(i,1,n){
        cin >> nodes[i].F;
        nodes[i].S=i;
    }
    sort(all(nodes));

    cf(i,1,n){
        ll need = nodes[i].F;
        if(need>i){
            cout << -1 << "\n";
            return;
        } 
        f(j,1,need){
            adj[nodes[i].S].pb(nodes[j].S);
        }
    }

    ll sm = 0;
    for(int i = 1; i <= n; i++){
       sm+=adj[i].size();
    }

    cout << sm << "\n";
    for(int i = 1; i <= n; i++){
        if(adj[i].empty()){
            continue;
        } else {
            for(auto e : adj[i]){
                cout << i << " " << e << "\n"; 
            }
        }
    }


    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t=1;
    while(t--){
        solve(); 
    }
}