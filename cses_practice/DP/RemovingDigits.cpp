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

ll mx(ll n){
    ll temp=0;
    while(n>0){
        temp=max(temp, n%10);
        n/=10;
    }
    return temp;
}

void solve(){
    
    ll n; cin >> n;
    if(n==0){
        cout << 0 << "\n";
        return;
    }
    if(n<10){
        cout << 1 << "\n";
        return;
    }

    ll sum=0;
    vll dp(n+1);
    f(i,1,10){
        dp[i]=1;
    }


    cf(i,10,n){
        dp[i]=dp[i-mx(i)]+1;
    }

    cout << dp[n] << "\n";
    
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}