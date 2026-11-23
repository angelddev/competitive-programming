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

    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    if(a>b){
        ll temp1=a;
        a=b;
        b=temp1;
        ll temp2 = c;
        c=d;
        d=temp2;
    }
    ll ans=0;
    if(c>=b){
        ans+=c-a;
        b=min(c, d);
        ans+=d-b;
    } else if(c<b){
        ans+=c-a;
        ans+=d-b;
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