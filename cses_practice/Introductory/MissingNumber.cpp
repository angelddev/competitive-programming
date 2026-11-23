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

   ll n; cin >> n;
   vll appearance(n, 0);
   ll x;
   for(ll i=0; i<n-1; i++){
    cin >> x;
    appearance[x-1]=1;
   }

   for(ll i=0; i<n; i++){
    if(appearance[i]==0){
        cout << i+1 << endl;
        return;
    }
   }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}