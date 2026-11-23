#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("03,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
using namespace __gnu_pbds;
using namespace std; 
typedef long double ld;

typedef tree<pll, null_type, less<pll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
const ll INF = 1e18; 
const ll mod = 1e9 + 7;
 
void solve(){
 
    string s1, s2; cin >> s1 >> s2;

    vvl dp(s1.size()+1, vll(s2.size()+1, 0));

    cf(i,0,s1.size()){
        dp[i][0]=i;
    }

    cf(i,0,s2.size()){
        dp[0][i]=i;
    }

    cf(i,1,s1.size()){
        cf(j,1,s2.size()){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1];
            } else {
                dp[i][j]=min(min(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1])+1;
            }
        }
    }

    cout << dp[s1.size()][s2.size()] << "\n";
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
}