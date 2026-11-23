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
    

    ll n; cin >> n;
    vll nums(n+1);
    f(i,0,n){
        cin >> nums[i];
    }

    map<ll, ll> mp;

    ll l = 0, r = 0, ans = 0;
    mp[nums[0]]=1;

    while(r<n){
        if(mp[nums[r]]>1){
            while(mp[nums[r]]>1){
                mp[nums[l]]--;
                l++;
            }
        }

        ans+=(r-l)+1;
        r++;
        mp[nums[r]]++;
        
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; //cin >> t;
    while(t--){
        solve(); 
    }
}

