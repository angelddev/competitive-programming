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
 
void solve(){
   
   ll n, q; cin >> n >> q;
   vll pfx(n);
   cin >> pfx[0];
   ll x;
   f(i,1,n){
    cin >> x;
    pfx[i]=pfx[i-1]+x;
   } 

   ll l, r;
   f(i,0,q){
    cin >> l >> r;
    if(l!=1){
        cout << pfx[r-1]-pfx[l-2] << "\n";
    } else cout << pfx[r-1] << "\n";
   }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    //ll t; cin >> t;
    //while(t--)
        solve();
}