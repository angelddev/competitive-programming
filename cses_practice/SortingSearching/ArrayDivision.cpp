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
    ll mx=0;
    f(i,0,n){
        cin >> nums[i];
        mx=max(mx, nums[i]);
    } 

    ll mid, l=0, r=INF;
    ll subarr;
    while(l<r){
        mid=(l+r)/2;
        ll sum=0;
        subarr=1;
        f(i,0,n){
            if(nums[i]>mid){
                subarr=k+1;
                break;
            }
            if(nums[i]+sum>mid){
                subarr++;
                sum=nums[i];
            } else sum+=nums[i];
        }

        if(subarr<=k){
            r=mid;
        } else l=mid+1;
    }

    cout << l << "\n";


}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    //ll t; cin >> t;
    //while(t--)
        solve();
}