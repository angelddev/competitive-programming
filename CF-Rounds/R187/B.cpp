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
    vpl digits;
    ll x=n;

    ll i=0;
    while(x>0){
        digits.pb({x%10, i});;
        i++;
        x/=10;
    }


    sort(digits.begin(), digits.end());
    ll ans=0, band=1, sum=0;
    f(i,0,digits.size()){
        if(digits[i].second==digits.size()-1)
            band--;
        if(sum+digits[i].first+band>=10){
            ans++;
        }
        else sum+=digits[i].first;
        
    }

    cout << ans << "\n";
    


    
}
 
int main(){
    ll t; cin >> t;
    while(t--){
        solve(); 
    }
}