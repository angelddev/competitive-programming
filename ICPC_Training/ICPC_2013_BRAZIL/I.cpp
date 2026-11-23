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

    ll n, c, p1, p2; cin >> n >> c >> p1 >> p2;
    vll holes(n+1);
    f(i,0,n){
        cin >> holes[i];
    }
    holes[n]=INF;

    sort(all(holes));
    vll dp(n+1);
    dp[n]=0;
    for(ll i=n-1; i>=0; i--){
        ll l1, l2;
        l1=upper_bound(all(holes), holes[i]+p1)-holes.begin();
        l2=upper_bound(all(holes), holes[i]+p2)-holes.begin();
        dp[i]=min(dp[l1]+p1, dp[l2]+p2);
    }

    cout << dp[0] << "\n";
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    //ll t; cin >> t;
    //while(t--)
        solve();
}