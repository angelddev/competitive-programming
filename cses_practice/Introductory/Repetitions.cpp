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

   string s;
   cin >> s;
   ll longest=1, mx=1, n=s.size();
   f(i, 1, n){
    if(s[i]==s[i-1])
        longest++;
    else {
        mx=max(longest, mx);
        longest=1;
    }
   }

   mx=max(longest, mx);

   cout << mx << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}