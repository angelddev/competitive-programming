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
 
ll t, n, m, k, a, b, tot; 
 
void solve(){
   
    ll n; cin >> n;

    vvl adj(n+1);
    vll nodes(n-1);
    vll parents(n+1);
    f(i,0,n-1){
        cin >> nodes[i];
    }
    string colors; cin >> colors;

    ll i=2;
    for(ll node: nodes){
        adj[node].pb(i);
        parents[i]=node;
        i++;
    }

    ll ans=0;
    stack<pll> st;
    st.push({1,0});

    vll curBlack(n+1), curWhite(n+1);
    while(!st.empty()){
        auto [u,state]=st.top();
        st.pop();
        if(state==0){
            st.push({u,1});
            if(colors[u-1]=='B') curBlack[u]++;
            else curWhite[u]++;
            for(ll j=adj[u].size()-1; j>=0; j--){
                st.push({adj[u][j],0});
            }
        }
        else {
            if(curBlack[u]==curWhite[u]){
                ans++;
            }
            if(u!=1){
                curBlack[parents[u]]+=curBlack[u];
                curWhite[parents[u]]+=curWhite[u];
            }
        }
    }

    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    ll t; cin >> t;
    while(t--)
        solve();
}