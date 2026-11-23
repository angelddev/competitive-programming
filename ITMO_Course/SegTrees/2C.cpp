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
ll arr[100007];

void build(ll node, ll l, ll r){
    if(l==r){
        tree[node] = arr[l];
        return;
    }

    ll mid = (l+r)/2;
    build(2*node, l, mid);
    build(2*node+1, mid+1, r);

    tree[node] = max(tree[node*2], tree[node*2+1]);
}

void update(ll node, ll l, ll r, ll pos, ll val){
    if(l==r){
        tree[node] = val;
        return;
    }

    ll mid = (l+r)/2;
    if(pos<=mid)
    update(2*node, l, mid, pos, val);
    else
    update(2*node+1, mid+1, r, pos,val);

    tree[node] = max(tree[node*2], tree[node*2+1]);
}

ll query(ll node, ll l, ll r, ll value){
    if(l==r){
        if(tree[node]<value){
            return -1;
        } else 
        return l;
    }

    ll mid = (l+r)/2;
    if(tree[2*node]>=value){
        return query(2*node, l, mid, value);
    } else {
        return query(2*node+1, mid+1, r, value);
    }
}

void solve(){
    
    ll n, q; cin >> n >> q;
    f(i,0,n){
        cin >> arr[i];
    }

    build(1, 0, n-1);
    ll idx, value, t;
    f(i,0,q){
        cin >> t;
        if(t==1){
            cin >> idx >> value;
            update(1, 0, n-1, idx, value);
        } else {
            cin >> value;
            cout << query(1, 0, n-1, value) << "\n";
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
