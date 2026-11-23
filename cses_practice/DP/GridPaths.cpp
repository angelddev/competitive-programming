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
    vector<vector<char>> mat(n, vector<char>(n));

    f(i,0,n){
        f(j,0,n){
            cin >> mat[i][j];
        }
    }

    if(mat[0][0]=='*'){
        cout << 0 << "\n";
        return;
    }
    vector<vll> dp(n, vll (n)); 

    dp[n-1][n-1]=1;

    for(int i=n-2;i>=0; i--){
        if(mat[i+1][n-1]!='*')
        dp[i][n-1]=dp[i+1][n-1];
    }
    for(int i=n-2;i>=0; i--){
        if(mat[n-1][i+1]!='*')
        dp[n-1][i]=dp[n-1][i+1];
    }

    for(int i=n-2; i>=0; i--){
        for(int j=n-2; j>=0; j--){
            if(mat[i+1][j]!='*')
            dp[i][j]+=MOD(dp[i+1][j]);
            if(mat[i][j+1]!='*')
            dp[i][j]+=MOD(dp[i][j+1]);
        }
    }

    cout << MOD(dp[0][0]) << "\n";
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}