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

    ll n, x; cin >> n >> x;
    vpl nums(n);
    f(i,0,n){
        cin >> nums[i].F;
        nums[i].S=i;
    }
    sort(all(nums));

    f(i,0,n){
        ll l=i+1, r=n-1, curr1=nums[i].F;
        while(l<r){
            ll curr = curr1+nums[l].F+nums[r].F;
            if(curr==x){
                cout << nums[i].S+1 << " " << nums[l].S+1 << " " <<nums[r].S+1 << "\n";
                return;
            } else if(curr>x){
                r--;
            } else l++;
        }
    }

    cout << "IMPOSSIBLE\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    //ll t; cin >> t;
    //while(t--)
        solve();
}