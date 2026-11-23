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
ll cont = 1;
vll tin, tout;
ll st[7000006];



void dfs(ll node, ll parent){

    tin[node] = cont++;
    for(ll v: adj[node]){
        if(v==parent) continue;
        dfs(v, node);
    }
    tout[node] = cont++;
}

void update(ll node, ll l, ll r, ll pos, ll val){

    if(l==r){
        st[node] = val;
        return;
    }

    ll mid = (l+r)/2;
    if(pos<=mid){
        update(2*node, l, mid, pos, val);
    } else {
        update(2*node+1, mid+1, r, pos, val);
    }

    st[node] = st[2*node]+st[node*2+1];

}

ll query(ll node, ll l, ll r, ll lq, ll rq){

    if(l>rq||r<lq){
        return 0;
    }
    if(l>=lq&&r<=rq){
        return st[node];
    }

    ll mid = (l+r)/2;
    return query(2*node, l, mid, lq, rq)+query(2*node+1, mid+1, r, lq, rq);

}

void solve(){

    ll n, m; cin >> n >> m;

    adj.assign(n+1, vll());
    tin.assign(n+1, 0);
    tout.assign(n+1, 0);

    vll vals(n+1);
    ll x, y;
    cf(i,1,n){
        cin >> x;
        vals[i] = x;
    }

    cf(i,1,n-1){
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    dfs(1, 0);

    cf(i,1,n){
        update(1, 1, 2*n, tin[i], vals[i]);
    }

    ll val;
    f(i,0,m){
        cin >> val;
        if(val==1){
            cin >> x >> y;
            update(1, 1, 2*n, tin[x], y);
        } else {
            cin >> x;
            cout << query(1, 1, 2*n, tin[x], tout[x]) << "\n";
        }
    }


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; //cin >> t;
    while(t--){
        solve(); 
    }
}

