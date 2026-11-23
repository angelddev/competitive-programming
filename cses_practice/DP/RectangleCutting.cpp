#include <bits/stdc++.h>

#define ll long long 
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

void solve(){
    
    ll a, b; cin >> a >> b;

    vvll dp(502, vll(502, INF));

    cf(i,1,500){
        dp[i][i] = 0;
    }


    cf(i, 1, 501){
        cf(j, 1, 501){
            f(k, 1, j){
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[i][j-k]+1);
                dp[j][i] = dp[i][j];
            }
        }
    }

    cf(i, 1, 501){
        cf(j, 1, 501){
            f(k, 1, j){
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[i][j-k]+1);   
            }

            f(k, 1, i){
                dp[i][j] = min(dp[i][j], dp[i-k][j]+dp[k][j]+1);
            } 
        }
    }
    ///

    cout << dp[a][b] << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; //cin >> t;
    while(t--){
        solve(); 
    }
}

