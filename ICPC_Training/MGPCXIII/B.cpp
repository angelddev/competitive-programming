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
const int LOG = 30;
vector<pll> blockCords;
vector<ll> blockPwr;
vector<ll> best;

vll tree;

void build(ll node, ll start, ll end) {
    if(start == end) {
        tree[node] = best[start];
        return;
    }
    ll mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}

void update(ll node, ll start, ll end, ll idx, ll val) {
    if(start == end) {
        best[idx] = val;
        tree[node] = val;
        return;
    }
    ll mid = (start + end) / 2;
    if(idx <= mid) update(2 * node, start, mid, idx, val);
    else update(2 * node + 1, mid + 1, end, idx, val);
    tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}

ll query(ll node, ll start, ll end, ll l, ll r) {
    if(r < start || end < l) return INF;
    if(l <= start && end <= r) return tree[node];
    ll mid = (start + end) / 2;
    return min(query(2 * node, start, mid, l, r), query(2 * node + 1, mid + 1, end, l, r));
}

void solve(){
    
    ll n; cin >> n;
    blockCords.assign(n+1, {});
    blockPwr.assign(n+1, 0);
    best.assign(n+1, INF);
    tree.assign(4*n + 4, INF);

    vector<char> lvl(n);
    f(i,0,n){
        cin >> lvl[i];
    }

    if(lvl[n-1]!='x'||lvl[0]!='x'){
        cout << -1 << "\n";
        return;
    }

    ll tmpcont=1;
    ll cont=-1;
    f(i,0,n){
        if((i==0||lvl[i-1]=='.')&&lvl[i]=='x'){
            cont++;
            blockCords[cont].F=i;
        } else if(lvl[i]=='x'){
            tmpcont++;
        } else if(lvl[i]=='.'&&(i!=0&&lvl[i-1]=='x')){
            blockCords[cont].S=i-1;
            blockPwr[cont]=tmpcont;
            tmpcont=1;
        }
    }
    blockCords[cont].S=n-1;
    blockPwr[cont]=tmpcont;
    best[blockCords[cont].F]=0;
    
    build(1, 0, n-1);

    ll bs = 0;
    for(ll i = cont-1; i>=0; i--){
        if(i == 0){
            bs = query(1, 0, n-1, 0, blockCords[0].S+blockPwr[0])+1;
        } else {
            update(1, 0, n-1, blockCords[i].F, query(1, 0, n-1, blockCords[i].S, blockCords[i].S+blockPwr[i])+1);
        }
    }
    if(bs>=INF) cout << -1 << "\n"; else 
    cout << bs << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t; cin >> t;
    while(t--){
        solve(); 
        blockCords.clear();
        blockPwr.clear();
        best.clear();
        tree.clear();
    }
}

