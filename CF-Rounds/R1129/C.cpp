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

void solve(){

    ll n, m;

    cin >> n >> m;

    vvll adj(n+1);

    ll x, y;
    f(i,0,n-1){
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    vll dis(n+1, -1);

    queue<ll> bfs;
    dis[n]=0;
    bfs.push(n);
    while(!bfs.empty()){
        ll node = bfs.front();
        bfs.pop();
        if(node==1) continue;
        for(ll el : adj[node]){
            if(dis[el]!=-1) continue;
            dis[el] = dis[node]+1;
            bfs.push(el);
        }
    }

    ll ans = dis[1];
    f(i,0,m){
        cin >> x;
        if(x==1) continue;
        ans = max(dis[x]+1, ans);
    } cout << ans << "\n";

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