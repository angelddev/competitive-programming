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

    ll a, b, c, m; cin >> a >> b >> c >> m;

    ll lcmall=lcm(lcm(a,b), c);

    ll subsall=m/lcmall;

    ll apts=subsall*2+((m/lcm(a,b))-subsall)*3+(m/lcm(a,c)-subsall)*3+((m/a)-((m/lcm(a,b))-subsall)-(m/lcm(a,c)))*6;
    ll bpts=subsall*2+((m/lcm(b,a))-subsall)*3+(m/lcm(b,c)-subsall)*3+((m/b)-((m/lcm(a,b))-subsall)-(m/lcm(b,c)))*6;
    ll cpts=subsall*2+((m/lcm(c,b))-subsall)*3+(m/lcm(a,c)-subsall)*3+((m/c)-((m/lcm(a,c))-subsall)-(m/lcm(b,c)))*6;

    cout << apts << " " << bpts << " " << cpts << "\n";

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    ll t; cin >> t;
    while(t--)
        solve();
}