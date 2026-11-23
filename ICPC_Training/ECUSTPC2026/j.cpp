#include <bits/stdc++.h>

#define ll long long 
#define endl '\n'
#define all(a) begin(a), end(a)
#define pll pair<ll, ll>
#define vll vector<ll>
#define vvll vector<vll>
#define vpl vector<pll>
#define f(i, s, e) for(ll i=s; i<e; i++)
#define cf(i, s, e) for(ll i=s; i<=e; i++)
#define rf(i, s, e) for(ll i=s; i>=e; i--)
#define F first
#define S second
#define pb push_back
using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9 +7;
const int LOG = 30;

ll n, x, y, a, b;
ll v[2000006];
ll dp[10000006];

ll val(ll k){
    if(k<=10000000 && dp[k]!=-1) return dp[k];  
    ll tot=b*k;
    f(i, 0, n){
        tot+=a*((max(0ll, v[i]-k*y)+x-1)/x);
    }
    if(k<=10000000) dp[k]=tot; 
    return tot;
}

ll ternary(ll mx){
    ll x=-1; 
    for(ll b=mx; b>=1; b/=2){
        while(val(x+b) > val(x+b+1)) x+=b;
    }
    return val(x+1);
}

void solve(){
    cin>>n>>x>>y>>a>>b; 
    ll mv=0;
    f(i, 0, n){
        cin>>v[i];
        mv=max(mv, v[i]);  
    }

    ll mn = INF;
    mn = min(mn, ternary(mv+5));
    mn = min(mn, ternary(mv/y));
    mn = min(mn, ternary(5));
    //cout<<mv<<"\n";
    // cf(i, 0, (mv/y)+5){
    //     cout<<val(i)<<" "; 
    // }cout<<"\n";
   cout << mn << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    memset(dp, -1, sizeof(dp)); 

    ll t=1;
    while(t--){
        solve(); 
    }
}