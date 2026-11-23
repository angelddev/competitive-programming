#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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

using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
 
const ll INF = 1e18; 
const ll mod = 998244353;

void solve(){

    ll n, k; cin >> n >> k;
    pbds A;

    f(i,1,n+1) A.insert(i);

    ll i=0; 
    while(!A.empty()){
        ll nat=*A.find_by_order((i+k)%A.size()); //value at index i+k
        i=(i+k)%A.size();
        cout << nat << " ";
        A.erase(nat);
    }
    cout << "\n";
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    //ll t; cin >> t;
    //while(t--)
        solve();
}