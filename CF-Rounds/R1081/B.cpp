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
    string s; cin >> s;

    ll ones=0, zeroes=0;
    vll indexes, indexez;
    f(i,0,n){
        if(s[i]=='1') {
            ones++;
            indexes.pb(i+1);
        } else {zeroes++; indexez.pb(i+1);}
    }

    if(ones==0||ones%2==0){
        ll sz=indexes.size();
        cout << ones << "\n";
        f(i,0,sz){
            cout << indexes[i] << " ";
        }cout << "\n";
    }
    else if(zeroes%2){
        ll sz=indexez.size();
        cout << zeroes << "\n";
        f(i,0,sz){
            cout << indexez[i] << " ";
        }cout << "\n";
    }
    else cout << -1 << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    ll t; cin >> t;
    while(t--)
    solve();
}