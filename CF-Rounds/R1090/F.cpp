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


void solve() {
    ll x, y;
    cin >> x >> y;

    ll n = x+y;
    if (x>y||(n%2==0&&x==0)) {
        cout << "NO\n";
        return;
    }

    vpl e;
    ll cur=1;
    if (n%2==1) {
        ll chains= x;
        ll leaves= y-x-1;
        f(i, 0, chains) {
            ll a = ++cur;
            ll b = ++cur;
            e.pb({1, a});
            e.pb({a, b});
        }
        f(i, 0, leaves) {
            ll v = ++cur;
            e.pb({1, v});
        }
    } else {
        ll cadenas = x - 1;
        ll leaves = y - x + 1;
        f(i, 0, cadenas) {
            ll a =++cur;
            ll b =++cur;
            e.pb({1, a});
            e.pb({a, b});
        }

        f(i,0,leaves) {
            ll v=++cur;
            e.pb({1, v});
        }
    }

    cout << "YES\n";
    for (auto [u, v] : e) {
        cout << u << " " << v << "\n";
    }
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    ll t; cin >> t;
    while(t--)
        solve();
}