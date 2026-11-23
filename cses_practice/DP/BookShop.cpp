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
    
    ll n, cap; cin >> n >> cap;
    
    vector<pair<int, int>> values(n+1);
    cf(i,1,n) cin>>values[i].first;
    cf(i,1,n) cin>>values[i].second;

    vector<vector<int>> dp(n+1, vector<int>(cap+1));

    cf(i,1,n){
        cf(j,1,cap){
            if(values[i].first>j){
                dp[i][j]=dp[i-1][j];
            }else{
                dp[i][j]=max(values[i].second+dp[i-1][j-values[i].first], dp[i-1][j]);
            }
        }
    }

    cout << dp[n][cap] << "\n";
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}