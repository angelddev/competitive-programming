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
 
void reverse_magic(ll n, string a, bool flip){
    if(a.size()==n){
        cout << a << "\n";
        return;
    }
    
    if(!flip){
        reverse_magic(n, "0"+a, 0);
        reverse_magic(n, "1"+a, 1);
    } else {
        reverse_magic(n, "1"+a, 0);
        reverse_magic(n, "0"+a, 1);
    }
}

void solve(){
    
    ll n; cin >> n;
    
    string a="";
    reverse_magic(n, a, 0);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    solve();
}