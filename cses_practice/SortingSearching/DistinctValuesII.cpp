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

    ll n, k; cin >> n >> k;

    vll nums(n);
    f(i,0,n) cin >> nums[i];

    if(n==1){
        cout << 1 << "\n";
        return;
    }

    map<ll, ll> freqs;
    ll l=0, r=0;
    ll diffs=0, ans=0;

    while(l<=r&&r!=n){
        if(freqs[nums[r]]==0){
            diffs++;
        }
        freqs[nums[r]]++;

        if(diffs>k){
            while(diffs>k){
                freqs[nums[l]]--;
                if(freqs[nums[l]]==0) diffs--;
                l++;
            }
        } 
        ans+=(r-l)+1;
        
        r++;

    }
    cout << ans << "\n";
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    //ll t; cin >> t;
    //while(t--)
        solve();
}