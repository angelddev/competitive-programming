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
 
ll t, n, m, k, a, b, tot; 
 
void solve(){
   
    ll n, x; cin >> n >> x;

    vector<string> words;

    string p;
    f(i,0,n){
        cin >> p;
        words.pb(p);
    }

    ll mn=INF, temp;
    f(i,0,n){
        f(j,i+1,n){
            temp=0;
            f(k,0,x)
            temp+=abs(words[j][k]-words[i][k]);
            mn=min(temp,mn);
        }
    }
    
    cout << mn << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    ll t; cin >> t;
    while(t--)
        solve();
}