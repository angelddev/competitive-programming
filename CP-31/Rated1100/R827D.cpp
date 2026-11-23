#include<bits/stdc++.h>
 
#define ll long long 
#define all(a) begin(a), end(a)
#define pll pair<ll, ll> 
#define vll vector<ll>
#define vvl vector<vll>
#define vpl vector<pll> 
#define f(i, s, e) for(ll i=s; i<e; i++)
#define cf(i, s, e) for(ll i=s; i<=e; i++)
#define rf(i, s, e) for(ll i=s; i<e; i--)
#define MOD(x) ((((x)%mod) + mod)%mod)
#define F first
#define S second
#define pb push_back 
using namespace std; 
typedef long double ld;
 
const ll INF = 1e18; 
const ll mod = 1e9 + 7;
 
ll t, n, m, k, a, b, tot; 
 
int gcd(ll a, ll b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void solve(){
    
    ll n; cin >> n;
    set<pll> nums;
    ll x;
    f(i,0,n){
        cin >> x;
        auto it = nums.lower_bound({x, -INF});
        if (it != nums.end() && it->first == x) {
            nums.erase(it);
        }
    nums.insert({x, i+1});    
    } 

    ll mx=-1;
    for(auto it1=nums.begin(); it1!=nums.end(); ++it1){
        for(auto it2=it1; it2!=nums.end(); ++it2){
            if(gcd(it1->first, it2->first)==1){
                ll temp=abs(it1->second + it2->second);
                mx=max(temp,mx);
            }
        }
    }

    cout << mx << endl;

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    ll t; cin >> t;
    while(t--)
    solve();
}