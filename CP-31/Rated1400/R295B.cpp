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

    ll n, m; cin >> n >>m;
    ll count=0;

    if(m<n){
        cout << n-m << "\n";
        return;
    }

    
    while(m!=n){
        if(m<n){
            count+=n-m;
            break;
        }
        if(m%2==0){
            m/=2;
        } else m++;
        count++;
    }

    cout << count << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    //ll t; cin >> t;
    //while(t--)
        solve();
}