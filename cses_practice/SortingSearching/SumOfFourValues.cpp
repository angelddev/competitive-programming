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
    vll nums(n);
    map<ll, pll> mp;
    f(i,0,n){
        cin >> nums[i];
    }
 
    f(i,0,n){
        f(j,i+1,n){
            ll goal=nums[i]+nums[j];
            mp[goal]={i,j};
        }
    }
    
    f(i,0,n){
        f(j,i+1,n){
            ll goal=x-(nums[i]+nums[j]);
            if (mp.count(goal)) {
                auto [a, b] = mp[goal];
                if(i!=a&&i!=b&&j!=b&&j!=a){
                    cout << i+1 << " " << a+1 << " " << b+1 << " " << j+1 << "\n"; 
                    return;
                }
            }
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