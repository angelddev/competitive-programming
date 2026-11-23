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

void solve(){
    
    ll n, k; cin >> n >> k;
    vll prices(n, 0);
    vll right(n);
    vll left(n);

    f(i,0,n){
        cin >> right[i];
    }
    f(i,0,n){
        cin >> left[i];
    }

    sort(right.begin(), right.end());
    sort(left.begin(), left.end());
    f(i,0,n){
        prices[i]=right[i]+left[i];
    }

    ll ans=0, sum=0;
    f(i,0,n){
        if(prices[i]+sum>k) break;
        else ans++;
        sum+=prices[i];
    }

    cout << ans << "\n";
}

int main(){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    // ll t; cin >> t;
    //while(t--)
     solve();
}