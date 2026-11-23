#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define vll vector<ll>
#define vpl vector<pll>
#define vvll vector<vll>
#define f(i, s, e) for(ll i=s; i<e; i++)
#define cf(i, s, e) for(ll i=s; i<=e; i++)
#define rf(i, s, e) for(ll i=s; i>=e; i--)
#define all(a) begin(a), end(a)
#define endl '\n'
#define pb push_back 
#define F first 
#define S second 
using namespace std; 

const ll INF = 1e18; 
const ll MOD = 1e9+7; 

ll n, m, k; 
vpl adj[300000];
ll vis[300000];
ll comp[300000];
vll eliminated;
ll flg = 1;

void dfs(ll node){

    vis[node] = 1;
    for(pll el: adj[node]){
        if(vis[el.F]) continue;
        else{
            dfs(el.F);
        }
        if(comp[el.F]<3){
            comp[node]+=comp[el.F];
        } else eliminated.pb(el.S);
    }
    comp[node]++;
    if(comp[node]>3) flg = 0;
}

void solve(){
    
    flg = 1;
    ll n; cin >> n;
    ll x, y;
    f(i,0,n-1){
        cin >> x >> y;
        adj[x].pb({y, i+1});
        adj[y].pb({x, i+1});
    }

    dfs(1);

    if(!flg||n%3!=0){
        cout << "-1\n";
    } else {
        cout << eliminated.size() << "\n";
        for(ll ad : eliminated){
            cout << ad << " ";
        }cout << "\n";
    }

    f(i,1,n+1){
        adj[i].clear();
        vis[i]=0;
        comp[i]=0;
        eliminated.clear();
    }

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
    cin>>t; 
    while(t--){
        solve(); 
    }
}