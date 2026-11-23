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


void solve(){

    ll n; cin >> n;

    vll arr(n+1);
    cf(i,1,n){
        cin >> arr[i];
    }

    vvll dp(n+1, vll(n+1));
    cf(i,1,n){
        dp[i][i] = arr[i];
    }

    vll pfx(n+2);
    pfx[1]=arr[1];
    cf(i,2,n){
        pfx[i]=pfx[i-1]+arr[i];
    }

    cf(i,1,n){
        ll l = 1, r = l+i;
        while(r<=n){
            dp[l][r] = max(arr[l]+((pfx[r]-pfx[l])-dp[l+1][r]), arr[r]+((pfx[r-1]-pfx[l-1])-dp[l][r-1]));
            l++, r++;
        }        
    }

    cout << dp[1][n] << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t=1; 
    while(t--){
        solve(); 
    }
}