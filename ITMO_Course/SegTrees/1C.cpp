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

pll tree[500005];
ll arr[100007];


void build(ll node, ll l, ll r){
    if(l==r){
        tree[node].F = arr[l];
        tree[node].S = 1;
        return;
    }

    ll mid = (l+r)/2;
    build(2*node, l, mid);
    build(2*node+1, mid+1, r);

    if(tree[node*2].F<tree[node*2+1].F){
        tree[node] = tree[node*2];
    } else if(tree[node*2].F>tree[node*2+1].F){
        tree [node] = tree[node*2+1];
    } else {
        tree[node].F = tree[node*2].F;
        tree[node].S = tree[node*2].S+tree[node*2+1].S;
    }

}

void update(ll node, ll l , ll r, ll pos, ll val){

    if(l==r){
        tree[node].F = val;
        tree[node].S = 1;
        return;
    }

    ll mid = (l+r)/2;
    if(pos<=mid){
        update(2*node, l, mid, pos, val);
    } else update(2*node+1, mid+1, r, pos, val);

    if(tree[node*2].F<tree[node*2+1].F){
        tree[node] = tree[node*2];
    } else if(tree[node*2].F>tree[node*2+1].F){
        tree [node] = tree[node*2+1];
    } else {
        tree[node].F = tree[node*2].F;
        tree[node].S = tree[node*2].S+tree[node*2+1].S;
    }

}

pll query(ll node, ll l , ll r, ll lq, ll rq){

    if(l>=lq&&r<=rq){
        return tree[node];
    }
    if(l>rq||r<lq){
        return {INF, 0};
    }

    ll mid = (l+r)/2;
    pll v1 = query(node*2, l, mid, lq, rq);
    pll v2 = query(node*2+1, mid+1, r, lq, rq);
    
    if(v1.F<v2.F){
        return v1;
    } else if(v1.F>v2.F){
        return v2;
    } else {
        v1.S+=v2.S;
        return v1;
    }
}

void solve(){
    ll n, q; cin >> n >>  q;

    f(i,0,n){
        cin >> arr[i];
    }

    build(1, 0, n-1);

    ll t, v1, v2;
    f(i,0,q){
        cin >> t >> v1 >> v2;
        if(t==1){
            update(1, 0, n-1, v1, v2);
        } else {
            pll p = query(1, 0, n-1, v1, v2-1);
            cout << p.F << " " << p.S << "\n";
        }
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
