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

    ll t; cin >> t;
    vector<vpl> adj(t+1);
    ll weight;
    cf(i,1,t){
        cf(j,1,t){
            cin >> weight; 
            adj[i].pb({j, weight});
        }
    }

    vvl dp(t+1, vll(t+1, INF));
    cf(i,1,t){
        dp[i][i]=0;
    }
    cf(i,1,t){
        f(j,0, adj[i].size()){
            dp[i][adj[i][j].F]=min(dp[i][adj[i][j].F], adj[i][j].S);
        }
    }
   

    vll active(t+1, 0);
    ll q=t, q1;
    deque<ll> queries;
    deque<ll> answers;
    f(i,0,q){
        cin >> q1;
        queries.push_front(q1);
    }
    f(i,0,q){
        q1=queries[i];
        active[q1]=1;
        ll sum=0;
        cf(k, q1, q1){
            cf(i,1,t){
                cf(j,1,t){
                    dp[i][j]=min(dp[i][j], dp[i][k]+dp[k][j]);
                }
            }
        }

        cf(i,1,t){
            cf(j,1,t){
                if(active[i]==1&&active[j]==1)
                sum+=dp[i][j];
            }
        }
        answers.push_front(sum);
    }
    f(i,0,t){
        cout << answers[i] << " ";
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