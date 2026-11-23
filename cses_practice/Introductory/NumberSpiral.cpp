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
    
    ll y, x; cin >> y >> x;

    ll ans=0;
    if(y>=x){
        if(y%2==0){
            ans=y*y;
            ans-=(x-1);
        } else {
            y=y-1;
            ans=y*y+1;
            ans+=(x-1);
        }
        cout << ans << endl;
        return;
    }

        if(x%2==1){
            ans=x*x;
            ans-=(y-1);
        } else {
            x=x-1;
            ans=x*x+1;
            ans+=(y-1);
        }
    
    cout << ans << endl;


    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t; cin >> t;
    while(t--)
    solve();
}