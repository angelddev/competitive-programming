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

    tree[node] = tree[2*node]+tree[node*2+1];
}

void update(ll node, ll l, ll r, ll pos){
    if(l==r){
        tree[node]^=1;
        return;
    }

    ll mid = (l+r)/2;
    if(pos<=mid){
        update(node*2, l, mid, pos);
    } else update(node*2+1, mid+1, r, pos);

    tree[node] = tree[node*2]+tree[node*2+1];
}

ll query(ll node, ll l, ll r, ll kth){
    if(l==r){
        return l;
    }

    ll mid = (l+r)/2;
    if(kth<=tree[2*node]){
        return query(2*node, l, mid, kth);
    } else {
        return query(2*node+1, mid+1, r, kth-tree[2*node]);
    }
}


void solve(){

    ll n, q; cin >> n >> q;

    f(i,0,n){
        cin >> arr[i];
    }
    build(1, 0, n-1);

    ll t, v1;
    f(i,0,q){
        cin >> t >> v1;
        if(t==1){
            update(1, 0, n-1, v1);
        } else {
            cout << query(1, 0, n-1, v1+1) << "\n";
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t= 1;
    while(t--){
        solve(); 
    }
}
