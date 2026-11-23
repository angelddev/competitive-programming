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
    vvl adj(n+1);
    ll x, root;
    cf(i,1,n){
        cin >> x;
        if(x==0) root=i;
        else
        adj[x].pb(i);
    }

    vll groups(n+1);
    cf(i,1,n){
        cin >> groups[i];
    }

    vll ans(n+1);
    vll freqs(n+1, 0);
    stack<pll> st;
    st.push({root, 0});
    ll count=0;
    while(!st.empty()){
        auto [u,state]=st.top();
        st.pop();
        if(state==0){
            if(freqs[groups[u]]==0){
                count++;
            }
            freqs[groups[u]]++;
            ans[u]=count;
            st.push({u, 1});
            for(ll i=0; i<adj[u].size(); i++){
                st.push({adj[u][i], 0});
            }
        }
        else {
            freqs[groups[u]]--;
            if(freqs[groups[u]]==0) count--;
        }
    }

    cf(i,1,n){
        cout << ans[i] << " ";
    }
    cout << "\n";

}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t=1; 
    while(t--){
        solve(); 
    }
}