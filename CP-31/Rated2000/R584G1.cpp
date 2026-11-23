#include <bits/stdc++.h>

#define ll long long 
#define endl '\n'
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

    vll nums(n);
    f(i,0,n){
        cin >> nums[i];
    }

    unordered_map<ll, pll> apps;

    f(i,0,n){
        if(apps[nums[i]].F==0){
            apps[nums[i]].F=i;
        }
        apps[nums[i]].S=i;
    }

    ll ans = 0;
    ll left = 0, right;
    while(left<n){
        right=apps[nums[left]].S;
        unordered_map<ll, ll> mp;

        ll idx = left;
        ll mx = 0;
        while(idx<=right){
            mp[nums[idx]]++;
            mx=max(mx, mp[nums[idx]]);
            right = max(right, apps[nums[idx]].S);
            idx++;
        }
        ans+= ((right-left)+1)-mx;
        left = right+1;
    }

    cout << ans << "\n";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1;
    while(t--){
        solve(); 
    }
}