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
    ll t, f, q; cin >> t >> f >> q;
    vector<vpl> adj(t+1);
    vll visited(t+1);
    ll x, y, weight;
    f(i,0,f){
        cin >> x >> y >> weight;
        adj[x].pb({y, weight});
    }

    vvl dp(t+1, vll(t+1, INF));

    cf(i,1,t){
        dp[i][i]=0;
    }
    cf(i,1,t){
        f(j,0, adj[i].size()){
            dp[i][adj[i][j].F]=min(dp[i][adj[i][j].F], adj[i][j].S);
            dp[adj[i][j].F][i]=dp[i][adj[i][j].F];
        }
    }
    cf(k,1,t){
        cf(i,1,t){
            cf(j,1,t){
                dp[i][j]=min(dp[i][j], dp[i][k]+dp[k][j]);
            }
        }
    }

    ll q1, q2;
    f(i,0,q){
        cin >> q1 >> q2;
        if(dp[q1][q2]>=INF) cout << "-1\n"; else
        cout << dp[q1][q2] << "\n";
    }
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    //ll t; cin >> t;
    //while(t--)
        solve();
}