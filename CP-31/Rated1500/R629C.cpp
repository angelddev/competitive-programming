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


void solve(){

    ll n; cin >> n;
    vpl adjs;
    vvll adj(n+1);
    ll x, y;
    f(i, 0, n-1){
        cin >> x >> y;
        adjs.pb({x, y});
        adj[x].pb(y);
        adj[y].pb(x);
    }

    int mx=-1;
    cf(i,1,n){
        if(adj[i].size()>2){
            mx=i;
            break;
        }
    }

    if(mx==-1){
        f(i,0,n-1){
            cout << i << "\n";
        }
        return;
    }

    ll cont = 0;
    ll cont2 = 3;
    for(auto e : adjs){
        if((e.first==mx||e.second==mx)&&cont<=2){
            cout << cont << "\n";
            cont++;
        } else {
            cout << cont2 << "\n";
            cont2++;
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