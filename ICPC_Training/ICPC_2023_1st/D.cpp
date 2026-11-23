#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("03,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
using namespace __gnu_pbds;
using namespace std; 
typedef long double ld;

typedef tree<pll, null_type, less<pll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
const ll INF = 1e18; 
const ll mod = 1e9 + 7;
 
void solve(){
 
    ll n, q; cin >> n >> q;
    pbds A;
    ll idx=0;
    
    ll x;
    f(i,0,n){
        cin >> x;
        A.insert({x, idx++});
    }

    ll type, l, r, change;
    f(i,0,q){
        cin >> type;
        if(type==1){
            cin >> change;
            auto it = A.lower_bound({change, -INF});
            if(it!=A.end() && it->first==change) continue;

            if(it!=A.end()) A.erase(it);    
            A.insert({change, idx++});
        }
        if(type==2){
            cin >> l >> r;
            ll idxl = A.order_of_key({l,-INF});
            ll idxr = A.order_of_key({r,INF}); 

            cout << idxr-idxl << "\n";
        }
    }
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
}