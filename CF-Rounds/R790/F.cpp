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
 
ll t, n, m, k, a, b, tot; 
 
void solve(){
   
    ll n, x; cin >> n >> x;
    vll nums(n);
    f(i,0,n) cin >> nums[i];

    sort(nums.begin(), nums.end());

    nums.pb(INF);
    vpl ranges; ll l=nums[0], r=nums[0], tmpcount=0;
    f(i,0,n){
        tmpcount++;
        if(tmpcount<x && nums[i+1]!=nums[i]){
            l=nums[i+1];
            r=nums[i+1];
            tmpcount=0;
        } 
        else if(tmpcount<x){
            r=nums[i+1];
        }
        else if(tmpcount>=x){
            r=nums[i];
            ranges.pb({l,r});
            if(nums[i+1]==nums[i]){
            }
            else if(nums[i+1]==nums[i]+1){
                tmpcount=0;
            } 
            else{
                l=nums[i+1];
                r=nums[i+1];
                tmpcount=0;
            }
        }
    }
    
    ll mx=-1, mxidx=-1;
    f(i,0,ranges.size()){
        if(ranges[i].second-ranges[i].first>mx){
            mxidx=i;
            mx=ranges[i].second-ranges[i].first;
        }
    }

    if(ranges.size()>0)
    cout << ranges[mxidx].first << " " << ranges[mxidx].second << "\n";
    else cout << -1 << "\n";

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    ll t; cin >> t;
    while(t--)
        solve();
}