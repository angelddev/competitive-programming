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


void solve(){
    ll n; cin >> n;
    vll nums(n), nums1(n);
    
    f(i,0,n){
        cin >> nums[i];
    }
    f(i,0,n){
        cin >> nums1[i];
    }
    ll sum=0;
    ll mn=0;
    f(i,0,n){
        sum+=max(nums[i], nums1[i]);
        mn=max(mn, min(nums[i], nums1[i]));
    }

    cout << sum+mn << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t; cin >> t; 
    while(t--){
        solve(); 
    }
    return 0;
}