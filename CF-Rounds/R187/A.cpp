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
 
void solve(){
 
    ll n, weight, capacity; cin >> n >> weight >> capacity;
    
    
    ll sum=0, totaltowers=1;
    f(i,1,n){
        if(sum+weight>capacity){
            totaltowers++;
            sum=0;
        } else {
            sum+=weight;
        }
    }

    cout << totaltowers << "\n";


}
 
int main(){
    ll t; cin >> t;
    while(t--){
        solve(); 
    }
}