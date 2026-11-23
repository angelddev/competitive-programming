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
 
ll t, n, m, k, a, b, tot; 
 

void solve(){
    ll n; cin >> n;

    vll bad(n);
    vll good(n);
    
    f(i,0,n) cin >> bad[i];
    f(i,0,n) cin >> good[i];

    vll compressed;
    compressed.pb(good[0]);
    f(i,1,n){
        if(good[i]!=good[i-1]){
            compressed.pb(good[i]);
        }
    }

    ll j=0;
    f(i,0,n){
        if(compressed[j]==bad[i]) j++;
        if(j==compressed.size()) break;
    }

    if(j==compressed.size()) cout << "YES" << "\n";
    else cout << "NO" << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    ll t; cin >> t;
    while(t--)
    solve();
}