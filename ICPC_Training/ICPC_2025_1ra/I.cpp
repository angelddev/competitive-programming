#include <bits/stdc++.h>

#define ll long long 
#define endl '\n'
#define all(a) begin(a), end(a)
#define pll pair<ll, ll>
#define vll vector<ll>
#define vvll vector<vll>
#define vpl vector<pll>
#define f(i, s, e) for(ll i=s; i<e; i++)
#define cf(i, s, e) for(ll i=s; i<=e; i++)
#define rf(i, s, e) for(ll i=s; i>=e; i--)
#define F first
#define S second
#define pb push_back
using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9 +7;
vvll adj;
vll traversal;

void dfs(ll node, ll parent){
    traversal.pb(node);
    for(ll e : adj[node]){
        if(e==parent) continue;
        dfs(e, node);
    }
    traversal.pb(node);
}

void solve(){

    ll n, q;
    cin >> n >> q;
    adj.assign(n+1, vll());
    vll topic(n+1);
    cf(i,1,n){
        cin >> topic[i];
    }
    ll x, y;
    f(i,1,n){
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    dfs(1, 0);
    vpl positions(n+1, {-1, -1});
    map<ll, vll> ranges;
    ll cont=1;
    for(ll node : traversal){
        if(positions[node].F==-1){
            positions[node]={cont, cont};
            ranges[topic[node]].pb(cont);
        }
        else positions[node].S=cont;
        cont++;
    }

    f(i,0,q){
        cin >> x >> y;
        auto it1 = lower_bound(all(ranges[y]), positions[x].F);
        if(it1==ranges[y].end()){
            cout << 0 << "\n";
            continue;
        }
        auto it2= upper_bound(all(ranges[y]), positions[x].S);
        if(it2==ranges[y].begin()){
            if(ranges[y][0]>positions[x].S)
            cout << 0 << "\n";
            else cout << 1 << "\n";
            continue;
        }
        cout << it2-it1<< "\n";
    } 

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t=1; 
    while(t--){
        solve(); 
    }
}