#include <bits/stdc++.h>

typedef  long long ll;

#define endl '\n'
#define sz(x) int((x).size())
#define all(a) begin(a), end(a)
#define pll pair<ll,ll>
#define vb vector<bool>
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vpl vector<pair<ll,ll>>
#define f(i,s,e) for(ll i = s; i<e;i++)
#define cf(i,s,e) for(ll i = s; i <=e; i++)
#define rf(i,s,e) for(ll i =s; i>=e; i--)
#define MOD(x) ((((x)%mod)+ mod)%mod)
#define F first 
#define S second
#define pb push_back
using namespace std;
typedef long double ld;

vpl adj[800005];
ll n, m, a, b, ord[800005], vis[800005], w[800005];
bool fin;
ll idx=1;

ll dfs(ll v){

    vis[v]=1; 
    //cout<<v<<" "; 

    ll k=m+1;
    while(true){
        if(idx > n) break; 
        pll target = {ord[idx], -1};
        auto it = lower_bound(adj[v].begin(), adj[v].end(), target);
        if(it!=adj[v].end()&&it->F==target.F){
            ll edge_idx = it->S;
            w[edge_idx] = k; 
            k--; 
            idx++;
            ll x = dfs(target.F);
            if(x==-1) return -1;
        } else {
            break; 
        }
    }

    for(auto [u, i]: adj[v]){
        if(vis[u]==0) {
            // cout << u << "\n";
            // cout << "Morí en: " << v << "\n";
            // cout << idx << "\n";
            return -1;
        } 
    }
    return 1; 

}

void solve(){
    fin=0;
    cin>>n>>m; 
    f(i, 0, m){
        cin>>a>>b; 
        adj[a].pb({b, i});
        adj[b].pb({a, i}); 
        w[i]=1; 
    }
    f(i, 0, n) cin>>ord[i]; 
    cf(i, 1, n) {
        sort(all(adj[i]));
    }
    if(dfs(1)==-1){
        cout<<"impossible\n"; 
        return;
    }
    else{
        f(i, 0, m){
            cout<<w[i]<<" "; 
        } cout<<"\n"; 
    }

}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    solve();
    return 0;
}