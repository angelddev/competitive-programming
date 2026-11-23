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

ll st[1600005];
vll euler;
vll hts;
vll first;
vvll adj;

void dfs(ll node, ll height){
    hts[node] = height;
    euler.pb(node);
    first[node] = euler.size()-1;
    for(ll e : adj[node]){
        dfs(e, height+1);
        euler.push_back(node);
    }
}

void build(ll node, ll l, ll r) {
    if (l == r) {
        st[node] = euler[l];
    } else {
        ll m = (l+r) / 2;
        build(node*2, l, m);
        build(node*2+1, m+1, r);

        ll left_node = st[node*2];
        ll right_node = st[node*2+1];
        if (hts[left_node] < hts[right_node]) {
            st[node] = left_node;
        } else {
            st[node] = right_node;
        }
    }
}

ll query(ll node, ll tl, ll tr, ll l, ll r) {
    if (l > r) 
        return -1;
    if (l == tl && r == tr) {
        return st[node];
    }
    ll m = (tl + tr) / 2;

    ll lft = query(node*2, tl, m, l, min(r, m));
    ll rgt= query(node*2+1, m+1, tr, max(l, m+1), r);

    if(lft==-1) return rgt;
    if(rgt==-1) return lft;

    if (hts[lft] < hts[rgt]) {
        return lft;
    } else {
        return rgt;
    }
}



void solve(){

    ll n, q; cin >> n >> q;
    adj.assign(n+1, vll());
    hts.assign(n+1, 0);
    first.assign(n+1, 0);
    ll p;
    cf(i,2,n){
        cin >> p;
        adj[p].pb(i);
    }

    dfs(1, 1);
    build(1, 0, euler.size()-1);

    ll x, y;
    f(i,0,q){
        cin >> x >> y;
        ll left_bound = min(first[x], first[y]);
        ll right_bound = max(first[x], first[y]);
        cout << query(1, 0, euler.size()-1, left_bound, right_bound) << "\n";
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