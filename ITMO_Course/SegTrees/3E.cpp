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

ll tree[500007];

void update(ll node, ll l, ll r, ll pos, ll val){
    if(l==r){
        tree[node]+=val;
        return;
    }

    ll mid = (l+r)/2;
    if(pos<=mid){
        update(2*node, l, mid, pos, val);
    } else update(2*node+1, mid+1, r, pos, val);

    tree[node] = tree[node*2]+tree[node*2+1];
}

ll query(ll node, ll l, ll r, ll lq, ll rq){
    if(l>=lq&&r<=rq){
        return tree[node];
    }
    if(l>rq||r<lq){
        return 0;
    }

    ll mid = (l+r)/2;
    return query(2*node, l, mid, lq, rq)+query(2*node+1, mid+1, r, lq, rq);
}

void solve(){

    ll n, q; cin >> n >> q;


    ll t, val, l, r;
    f(i,0,q){
        cin >> t;
        if(t==1){
            cin >> l >> r >> val;
            update(1, 0, n, l, val);
            update(1, 0, n, r, -val);
        } else {
            cin >> val;
            cout << query(1, 0, n, 0, val) << "\n";
        }
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
