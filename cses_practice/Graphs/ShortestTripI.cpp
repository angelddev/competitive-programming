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
    ll t, f; cin >> t >> f;
    vector<vpl> adj(t+1);
    vll visited(t+1);
    ll x, y, weight;
    f(i,0,f){
        cin >> x >> y >> weight;
        adj[x].pb({weight, y});
    }

    vll weights(t+1, 0);
    f(i,2,t+1){
        weights[i]=INF;
    }

    
    priority_queue<pll, std::vector<pll>, std::greater<pll>> next;
    next.push({0, 1});
    while(!next.empty()){
        ll w = next.top().F;
        ll n= next.top().S;
        next.pop();
        if(w>weights[n]) continue;  
        visited[n] = 1;
        for(pll neighbor : adj[n]){
            if(visited[neighbor.S]==0){
                if(neighbor.first+w<weights[neighbor.S]){
                    weights[neighbor.S]=neighbor.first+w;
                    next.push({neighbor.first+w, neighbor.S});
                } else continue;
            } else continue;
        }
    }

    f(i,1,t+1){
        cout << weights[i] << " ";
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