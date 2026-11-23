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

    ll n, m; cin >> n >> m;

    vll nums(n+1);
    cf(i,1,n) cin >> nums[i];

    vvl dp(n+1, vll(m+1));

    if(nums[1]==0){
        cf(i,1,m){
            dp[1][i]=1;
        }
    } else {
        dp[1][nums[1]]=1;
    }

    cf(i,2,n){
        if(nums[i]!=0){
            dp[i][nums[i]]+=dp[i-1][nums[i]]%mod;
            if(nums[i]!=1)
                dp[i][nums[i]]+=dp[i-1][nums[i]-1]%mod;
            if(nums[i]!=m)
                dp[i][nums[i]]+=dp[i-1][nums[i]+1]%mod;
            continue;
        }
        cf(j,1,m){
            dp[i][j]+=dp[i-1][j]%mod;
            if(j!=1)
                dp[i][j]+=dp[i-1][j-1]%mod;
            if(j!=m)
                dp[i][j]+=dp[i-1][j+1]%mod;
        }
        
    }

    ll sum=0;
    cf(i,0,m){
        sum=(sum%mod+dp[n][i]%mod)%mod;
    }

    cout << sum << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    //ll t; cin >> t;
    //while(t--)
    solve();
}