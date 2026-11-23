#include<bits/stdc++.h>
#define ll long long 
#define all(a) begin(a), end(a)
#define pll pair<ll, ll> 
#define vll vector<ll>
#define vvl vector<vll>
#define vpl vector<pll> 
#define f(i, s, e) for(ll i=s; i<e; i++)
#define cf(i, s, e) for(ll i=s; i<=e; i++)
#define rf(i, s, e) for(ll i=s; i<e; i--)
#define MOD(x) ((((x)%mod) + mod)%mod)
#define F first
#define S second
#define pb push_back 
using namespace std; 
typedef long double ld;
 
const ll INF = 1e18; 
const ll mod = 1e9 + 7;

void solve(){
    ll x, y; 
    cin >> x >> y;
    
    ll target = x-2*y;

    if (target%3!=0) {
        cout << "NO\n";
        return;
    }
    
    ll k=target/3;
    ll c_min=max(0LL, -y);
    
    if (k>=2*c_min) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    ll t; 
    cin >> t;
    while(t--)
        solve();
        
    return 0;
}