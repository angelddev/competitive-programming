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

void solve(){
    ll n; 
    cin >> n;
    string x; 
    cin >> x;

    ll poss =1;
    ll strt = 0;

    if (n%2!=0) {
        if (x[0] =='b') {
            poss=0;
        }
        strt = 1;
    }
    for (ll i = strt; i < n; i+=2) {
        if (x[i]!='?'&&x[i+1]!='?'&&x[i]==x[i+1]) {
            poss=0;
            break;
        }
    }

    if (poss) cout << "YES" << "\n";
    else cout << "NO" << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    ll t; 
    cin >> t;
    while(t--)
        solve();
    
    return 0;
}