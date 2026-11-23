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

struct seg{
    ll suf, pref, sum, best;
};

seg tree[500006];
ll arr[100007];



void build(ll node, ll l, ll r){
    if(l==r){
        tree[node].sum = arr[l];
        tree[node].suf = arr[l];
        tree[node].pref = arr[l];
        tree[node].best = arr[l];
        return;
    }

    ll mid = (l+r)/2;
    build(node*2, l, mid);
    build(node*2+1, mid+1, r);

    tree[node].sum = tree[node*2+1].sum+tree[node*2].sum;
    tree[node].suf=max(tree[node*2+1].suf, tree[node*2+1].sum+tree[node*2].suf);
    tree[node].pref = max(tree[node*2].pref, tree[node*2].sum+tree[node*2+1].pref);
    tree[node].best = max({tree[node*2].best, tree[node*2+1].best, tree[node*2+1].pref+tree[node*2].suf});
}

void update(ll node, ll l, ll r, ll pos, ll val){
    if(l==r){
        tree[node].sum = val;
        tree[node].suf = val;
        tree[node].pref = val;
        tree[node].best = val;
        return;
    }

    ll mid = (l+r)/2;
    if(pos<=mid)
    update(node*2, l, mid, pos, val);
    else update(node*2+1, mid+1, r, pos, val);

    tree[node].sum = tree[node*2+1].sum+tree[node*2].sum;
    tree[node].suf=max(tree[node*2+1].suf, tree[node*2+1].sum+tree[node*2].suf);
    tree[node].pref = max(tree[node*2].pref, tree[node*2].sum+tree[node*2+1].pref);
    tree[node].best = max({tree[node*2].best, tree[node*2+1].best, tree[node*2+1].pref+tree[node*2].suf});
}

seg query(ll node, ll l, ll r, ll lq, ll rq){
    if(l>=lq&&r<=rq){
        return tree[node];
    }
    if(l>rq||r<lq){
        seg s;
        s.best=0; s.pref=0; s.suf=0; s.sum=0;
        return s;
    }

    ll mid = (l+r)/2;
    seg s1 = query(2*node, l, mid, lq, rq);
    seg s2 = query(2*node+1, mid+1, r, lq, rq);

    seg s3;
    s3.sum = s2.sum+s1.sum;
    s3.suf=max(s2.suf, s2.sum+s1.suf);
    s3.pref = max(s1.pref, s1.sum+s2.pref);
    s3.best = max({s1.best, s2.best, s2.pref+s1.suf});

    return s3;
}

void solve(){

    ll n, q; cin >> n >> q;
    f(i,0,n){
        cin >> arr[i];
    }
    build(1, 0, n-1);

    cout << max(query(1, 0, n-1, 0, n-1).best, 0ll) << "\n";
    ll idx, value;
    f(i,0,q){
        cin >> idx >> value;

        update(1, 0, n-1, idx, value);
        cout << max(query(1, 0, n-1, 0, n-1).best, 0ll) << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1;
    while(t--){
        solve(); 
    }
}
