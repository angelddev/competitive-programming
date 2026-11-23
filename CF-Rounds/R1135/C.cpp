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

ll power(ll b, ll e){
    ll ans = 1;
    b %= MOD;
    while (e > 0) {
        if (e & 1)
            ans = (ans * b) % MOD;
        e >>= 1;
        b = (b * b) % MOD;
    }
    return ans;
}

void solve(){
 
    ll n; cin >> n;

    ll x;
    map<ll, ll> mp;
    vll nums;
    f(i,0,n){
        cin >> x;
        mp[x]++;
    }

    for(pll el : mp){
        if(el.S==1){
            nums.pb(el.F);
        } else nums.clear();
    }
    reverse(all(nums));

    ll ans = 1;
    for(ll i = 0; i < nums.size(); i++){
        ans = (ans+power(nums[i]-1, i+1))%MOD;
    }
    cout << ans << "\n";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; cin >> t;
    while(t--){
        solve(); 
    }
}

