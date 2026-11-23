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
#define mod 1000000007
using namespace std;

const ll INF = 1e9;
const ll MOD = 1e9 +7;

ll t, n, m, k, a, b; 

void solve(){
    ll n;
    cin >> n;
    vll nums(n);
    f(i,0,n){
        cin >> nums[i];
    }
    reverse(all(nums));

    if(n==1){
        cout << 0 << "\n";
    }
    ll l=0, r=1, currsum=0, mx=0;
    while(r!=n){
        if(nums[r]<nums[l]){
            currsum+=nums[r];
            r++;
        } else {
            ll ans=min(nums[l], nums[r])*((r-l)-1);
            ans-=currsum;
            mx=max(ans, mx);
            currsum=0;
            l=r;
            r++;
        }
    }
    reverse(all(nums));
    l=0, r=1, currsum=0;
    while(r!=n){
        if(nums[r]<nums[l]){
            currsum+=nums[r];
            r++;
        } else {
            ll ans=min(nums[l], nums[r])*((r-l)-1);
            ans-=currsum;
            mx=max(ans, mx);
            currsum=0;
            l=r;
            r++;
        }
    }
    cout << mx << "\n";


}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    t=1; 
    while(t--){
        solve(); 
    }
}