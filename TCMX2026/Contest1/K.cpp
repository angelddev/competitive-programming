#include <bits/stdc++.h>

#define ll long long 
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
const int LOG = 30;

vvll adj;
vll inD;
vll val;
vector<multiset<ll, greater<ll>>> merged;
ll ans = 0;

void score(ll node){

    queue<ll> children;

    for(ll v : adj[node]){
        score(v);
        children.push(v);
    }

    if(val[node]>-1){
        children.push(node);
        merged[node].insert(val[node]);
    }
    
    if(adj[node].size()<1){
        return;
    }

    //merge all children

    while(children.size()>1){
        ll v1 = children.front();
        children.pop();
        ll v2 = children.front();
        children.pop();

        if(merged[v2].size()>merged[v1].size()){
            swap(merged[v1], merged[v2]);
        } 

        for(ll val2 : merged[v2]){
            merged[v1].insert(val2);
        }

        merged[v2].clear();
        children.push(v1);
    }

    swap(merged[children.front()], merged[node]);
    if(children.front()!=node){
        merged[children.front()].clear();
    }

    if(val[node]>-1){
        return;
    } else {
        if(merged[node].size()>0){
            ans+= *(merged[node].begin());
            merged[node].erase(merged[node].begin());
        }
        return;
    }
}


void solve(){
    
    ll n, m; cin >> n >> m;
    adj.assign(n+1, vll());
    inD.assign(n+1, 0);
    merged.assign(n+1, multiset<ll, greater<ll>>());
    val.assign(n+1, 0);

    cf(i,1,n){
        cin >> val[i];
    }

    ll x, y;  
    f(i,0,m){
        cin >> x >> y;
        adj[x].pb(y);
        inD[y]++;
    }

    vll startTopos;
    cf(i,1,n){
        if(inD[i]==0){
            startTopos.pb(i);
        }
    }

    for(ll t : startTopos){
        score(t);
    }

    cout << ans << "\n";
    ans = 0;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; cin >> t;
    while(t--){
        solve(); 
        adj.clear();
        inD.clear();
        merged.clear();
        val.clear();
    }
}

