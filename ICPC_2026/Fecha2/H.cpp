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

ll tree[4*100009];

void update(ll node, ll l, ll r, ll idx, ll val){
    if(l==r){
        tree[node] = max(val, tree[node]);
        return;
    }

    ll mid = (l+r)/2;

    if(idx<=mid)
        update(2*node, l, mid, idx, val);
    else
        update(2*node+1, mid+1, r, idx, val);

    tree[node] = max(tree[2*node], tree[2*node+1]);
}

ll query(ll node, ll l, ll r, ll ql, ll qr){
    if(r < ql || l > qr){
        return 0;
    }

    if(ql <= l && r <= qr){
        return tree[node];
    }
    ll mid = (l + r) / 2;

    ll leftAns = query(2*node, l, mid, ql, qr);
    ll rightAns = query(2*node+1, mid+1, r, ql, qr);

    return max(leftAns, rightAns);
}

void solve(){

    ll n; cin >> n;
    vll r(n), k(n);
    ll mxR=0;
    f(i,0,n){
        cin >> r[i];
        mxR=max(mxR, r[i]);
    }
    f(i,0,n){
        cin >> k[i];
    }
    vll t(n);
    t[0]=r[0]+k[0];

    update(1, 0, mxR, r[0], t[0]);
    ll door=0;

    f(i,1,n){
        door=max(door+1, query(1, 0, mxR, 0, r[i]));
        t[i]=door+r[i]+k[i];
        update(1, 0, mxR, r[i], t[i]);
    }

    ll mx=0;
    f(i,0,n){
        mx=max(t[i], mx);
    }
    cout << mx << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t=1; 
    while(t--){
        solve(); 
    }
}