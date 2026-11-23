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
    vll a(n);
    f(i,0,n) cin >> a[i];
    ll k = -1;
    ll mx=-1;
    f(i,1,n){
        if(a[i]<a[i-1]){
            k=max(k, a[i-1]-a[i]);
            a[i]=a[i-1];
        } else{
            mx=(mx, k);
        }
    }
    mx=(mx, k);
    cout << mx << endl;

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    ll t; cin >> t;
    while(t--)
    solve();
}