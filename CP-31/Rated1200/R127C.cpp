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
   
    ll n, x; cin >> n >> x;
    vll arr(n);
    f(i,0,n) cin >> arr[i];
    sort(arr.begin(), arr.end());
    vll pfx(n);
    pfx[0]=arr[0];
    f(i,1,n) pfx[i]=pfx[i-1]+arr[i];

    ll ans=0;
    ll sum;
   f(i,1,n+1){
    if(pfx[i-1]>x) break;
    ll rem=x-pfx[i-1];
    sum=rem/i+1;
    ans+=sum;
   }
   cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    ll t; cin >> t;
    while(t--)
        solve();
}