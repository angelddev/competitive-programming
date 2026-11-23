#include <bits/stdc++.h>
#pragma GCC optimize("03,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#define ll long long 
#define all(a) begin(a), end(a)
#define pll pair<ll, ll>
#define vll vector<ll>
#define vvll vector<vll>
#define vpl vector<pll>
#define f(i, s, e) for(ll i=s; i<e; i++)
#define cf(i, s, e) for(ll i=s; i<=e; i++)
#define rf(i, s, e) for(ll i=s; i>=e; i--)
#define F first
#define S second
#define pb push_back
using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9 +7;
const int LOG = 30;


void solve(){
 

    ll n, q; cin >> n >> q;
    
    vector<pair<pll, pll>> areas;

    ll x1, x2, y1, y2;
    f(i,0,n){
        cin >> x1 >> y1 >> x2 >> y2;
        areas.pb({{x1, x2}, {y1, y2}});
    }


    
    f(i,0,q){
        cin >> x1 >> y1;
        ll ans = 0;
        for(auto a : areas){
            if(x1>=a.F.F&&x1<=a.F.S&&y1>=a.S.F&&y1<=a.S.S){
                ans++;
            }
        }

         cout << ans << "\n";
    }
    
   


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; //cin >> t;
    while(t--){
        solve(); 
    }
}

