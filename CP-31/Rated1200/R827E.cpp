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

    ll n, q; cin >> n >> q;
    vll pfx(n), pfxmx(n), questions(q);
    vll steps(n);
    
    f(i,0,n){
        cin >> steps[i];
    }
    
    pfx[0] = steps[0];
    pfxmx[0] = steps[0];

    f(i,1,n) pfx[i] = steps[i]+pfx[i-1];
    f(i,1,n) pfxmx[i] = max(steps[i], pfxmx[i-1]);
    
    f(i,0,q) cin >> questions[i];
    
    f(i,0,q){
        auto it = upper_bound(pfxmx.begin(), pfxmx.end(), questions[i]);
        if(it==pfxmx.begin()){
            cout << 0 << " ";
        }
        else {
            ll idx = (prev(it)-pfxmx.begin());
            cout << pfx[idx] << " ";
        }
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