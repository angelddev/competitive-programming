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
 
ll t, n, m, k, a, b, tot; 
 
void solve(){
   
    ll n, q; cin >> n >> q;

    vll sugar(n);
    f(i,0,n) cin >> sugar[i];
    vll queries(q);
    f(i,0,q) cin >> queries[i];

    sort(sugar.rbegin(), sugar.rend());
    vll pfx(n);
    pfx[0]=sugar[0];
    f(i,1,n) pfx[i]=pfx[i-1]+sugar[i];

    f(i,0,q){
        auto it=lower_bound(pfx.begin(), pfx.end(), queries[i]);
        if(it==pfx.end()) cout << "-1\n";
        else {
            ll idx=it-pfx.begin();
            cout << idx+1 << "\n";
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    ll t; cin >> t;
    while(t--)
        solve();
}