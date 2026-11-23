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
   
    ll n; cin >> n;

    string s; cin >> s;
    string copy=s;

    f(i,1,s.length()-1){
        if(copy[i-1]=='1'&&copy[i+1]=='1'){
            copy[i]='1';
        }
    }


    
    f(i,1,s.length()-1){
        if(copy[i-1]=='1'&&copy[i+1]=='1'){
            copy[i]='0';
        }
    }
    ll mnones=count(copy.begin(), copy.end(), '1');

    f(i,1,s.length()-1){
        if(s[i-1]=='1'&&s[i+1]=='1'){
            s[i]='1';
        }
    }

    ll mxones=count(s.begin(), s.end(), '1');


    cout << mnones << " " << mxones << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    ll t; cin >> t;
    while(t--)
        solve();
}