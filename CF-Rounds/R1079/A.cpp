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
 
long long digit_sum(long long y) {
    long long s = 0;
    while (y) {
        s += y % 10;
        y /= 10;
    }
    return s;
}

void solve(){
    
    ll n; cin >> n;

    int count = 0;
    for (long long y =n; y <=n+90; y++){
        if (y-digit_sum(y)==n)
            count++;
        }
    cout <<count<<"\n";
}





int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    ll t; cin >> t;
    while(t--)
    solve();
}