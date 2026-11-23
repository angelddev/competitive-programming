#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define vll vector<ll>
#define vpl vector<pll>
#define vvll vector<vll>
#define f(i,s,e) for(ll i=s; i<e; i++)
#define cf(i,s,e) for(ll i=s; i<=e; i++)
#define rf(i,s,e) for(ll i=s; i>=e; i--)
#define all(a) begin(a), end(a)
#define pb push_back
#define F first
#define S second
#define endl '\n'
using namespace std; 

const ll MOD = 1e9+7, INF = 1e18;

ll n, m, k; 
ll a[1005][1005]; 
pll dp[1005][1005]; 
pll pos[1000006]; 

void solve(){
    cin>>n; 
    vpl row(n+5, {0, 0}), col(n+5, {0, 0});

    cf(i, 1, n){
        cf(j, 1, n){
            cin>>a[i][j];
            pos[a[i][j]] = {i, j}; 
        }
    }

    ll ans=0; 
    rf(k, n*n, 1){
        ll i = pos[k].F, j = pos[k].S;  
        dp[i][j].F = row[j].S + 1;  
        dp[i][j].S = col[i].F + 1;  
        col[i].F = max(col[i].F, dp[i][j].F); 
        col[i].S = max(col[i].S, dp[i][j].S);
        row[j].F = max(row[j].F, dp[i][j].F);
        row[j].S = max(row[j].S, dp[i][j].S);
        // cf(x, 1, n) cout<<"("<<col[x].F<<", "<<col[x].S<<") "; cout<<"\n";
        // cf(x, 1, n) cout<<"("<<row[x].F<<", "<<row[x].S<<") "; cout<<"\n\n";
        ans = max({ans, dp[i][j].F, dp[i][j].S});
    }

    // cf(i, 1, n){
    //     cf(j, 1, n){
    //         cout<<"("<<dp[i][j].F<<", "<<dp[i][j].S<<") "; 
    //     } cout<<"\n"; 
    // }
    cout<<ans<<"\n"; 
}

int main(){
    #ifdef DEBUG 
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout);
    #else 
        ios_base::sync_with_stdio(0); 
        cin.tie(NULL); 
    #endif

    ll t=1;
    // cin>>t; 
    while(t--){
        solve(); 
    }
}