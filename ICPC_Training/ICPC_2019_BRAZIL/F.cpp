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


struct event{
    ll t, type, start, stage, pts; 
    // type, bool type
};
 
bool ord(event a, event b){
    if(a.t == b.t) return a.type<b.type;
    else return a.t<b.t;
}
 
vector<event> events; 
ll dp[86405][1028]; 
 
void solve(){

    ll n, t, s, e, o;
    cin>>n; 
    f(i, 0, n){
        cin>>t; 
        f(j, 0, t){
            cin>>s>>e>>o; 
            events.pb({s, 1, 0, i, o});
            events.pb({e, 0, s, i, o});
        }
    }
    sort(all(events), ord);
    memset(dp, -1, sizeof(dp));
    vll best(1<<n, -1);  
    best[0] = 0;

    for(auto [t, type, start, stage, pts]: events){
        if(type==1){
            f(i, 0, 1<<n) dp[t][i] = best[i]; 
        } else {
            f(i,0,1<<n){
                if(dp[start][i]>=0){
                    best[i|1<<stage]=max(best[i|1<<stage], dp[start][i]+pts);
                }
            }
        }
    
    }

    if(best[(1<<n)-1]!=-1){
        cout << best[(1<<n)-1] << "\n";
    }
    else cout << "-1\n";

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    //ll t; cin >> t;
    //while(t--)
        solve();
}