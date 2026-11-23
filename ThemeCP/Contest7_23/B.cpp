#include <bits/stdc++.h>

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
 
    ll n; cin >> n;

    map<ll, pll> nums;
    ll x, y;
    f(i,0,n){
        cin >> x >> y;
        if(y>nums[x].F){
            nums[x].F=y;
            nums[x].S=i+1;
        }
    }
    

    ll lst = 0, sm = 0;
    vll ans;
    for(auto emm : nums){
        pll el = emm.S;
        if(el.F<=lst) continue;
        ans.pb(el.S);
        lst = el.F;
    }

    cout << ans.size() << "\n";
    for(ll el : ans){
        cout << el << " ";
    } cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; cin >> t;
    while(t--){
        solve(); 
    }
}

