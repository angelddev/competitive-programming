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
const ll mod = 1e9 + 7;
 
ll t, n, m, k, a, b, tot; 
 
void solve(){
    ll n; cin >> n;
    vll arr(n + 1);
    cf(i, 1, n) cin >> arr[i];

    cf(i, 1, n) {
        ll val = arr[i];
        ll idx = i;
        while (val % 2 == 0) val /= 2;
        while (idx % 2 == 0) idx /= 2;

        if (val != idx) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    ll t; cin >> t;
    while(t--)
        solve();
}