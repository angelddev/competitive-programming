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

tuple<ll, ll, ll> extendedGcd(ll a, ll b){
    if (b==0){
        if(a>0) return{a,1,0};
        else return {-a,-1,0};
    }else{
        auto[d, x, y] = extendedGcd(b,a%b);
        return {d,y,x-y*(a/b)};
    }
}
 
ll  modularInverse(ll a, ll m){
    auto[d,x,y] = extendedGcd(a,m);
    if(d!=1)return -1;
    if(x<0) x+=m;
    return x;
}

void solve(){

    ll n; cin >> n;
    vvl adj(n+1);
    vvl adj2(n+1);
    ll x;
    cf(i,2,n){
        cin >> x;
        adj[x].pb(i);
        adj2[i].pb(x);
    }

    queue<ll> bfs;
    vll distance(n+1, -1);
    cf(i,1,n){
        if(adj[i].size()==0){
            distance[i]=1;
            bfs.push(i);
        }
    }


    while(!bfs.empty()){
        ll node = bfs.front();
        bfs.pop();
        for(ll boss : adj2[node]){
            if(distance[boss]==-1){
                distance[boss]=distance[node]+1;
                bfs.push(boss);
            }
        }
        for(ll report : adj[node]){
            if(distance[report]==-1){
                distance[report]=distance[node]+1;
                bfs.push(report);
            }
        }
    }

    ll sum=0;
    cf(i,1,n){
        sum+=distance[i];
    }
    ll ans= (sum*modularInverse(n, mod))%mod;
    cout << ans << "\n";

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    //ll t; cin >> t;
    //while(t--)
        solve();
}