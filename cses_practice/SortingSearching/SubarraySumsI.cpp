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
const ll mod = 1e9 + 7;
 
ll t, n, m, k, a, b, tot; 
 
void solve(){
   
    ll n, x; cin >> n >> x;
    vll nums(n);
    f(i,0,n) cin >> nums[i];
    ll ans=0, l=0, r=0, band=1, starter=0, sm=nums[0];
    while(band){
        if(sm<x){
            if(r!=n-1){
                r++;
                sm+=nums[r];
            }
            else band=0;
        }
        if(sm>=x){
            if(sm==x)
            ans++;
            if(r==l){
                if(r!=n-1){
                    sm-=nums[starter];
                    starter++;
                    r++;
                    l++;
                    sm+=nums[r];
                } else band=0;
            } else{
                sm-=nums[starter];
                starter++;
                l++;
            }
        }
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