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

    ll n; cin >> n;
    vll ans;    
    ll h=3*n;
    ll l=1;
    ll c=0;
    while(c<n){
        ans.pb(h);
        ans.pb(l);
        ans.pb(h-1);
        c++;
        h-=2;
        l++;
    }
    f(i,0,ans.size()){
        cout << ans[i] << " ";
    }
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    ll t; cin >> t;
    while(t--)
        solve();
}