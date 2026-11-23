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

ll arr[300009];
pll st[1000005];

void build(ll node, ll l, ll r){

    if(l==r){
        st[node].F = arr[l];
        st[node].S = arr[l];
        return;
    }

    ll mid = (l+r)/2;
    build(2*node, l, mid);
    build(2*node+1, mid+1, r);

    st[node].F = max(st[node*2].F, st[2*node].S+st[2*node+1].F);
    st[node].S = st[2*node].S+st[2*node+1].S;
    
}

void update(ll node, ll l, ll r, ll pos, ll val){

    if(l==r){
        st[node].F = val;
        st[node].S = val;
        return;
    }

    ll mid = (l+r)/2;

    if(pos<=mid)
    update(2*node, l, mid, pos, val);
    else 
    update(2*node+1, mid+1, r, pos, val);

    st[node].F = max(st[node*2].F, st[2*node].S+st[2*node+1].F);
    st[node].S = st[2*node].S+st[2*node+1].S;
}


pll query(ll node, ll l, ll r, ll lq, ll rq){

    if(l>=lq&&r<=rq){
        return st[node];
    }
    if(l>rq||r<lq){
        return {0, 0};
    }


    ll mid = (r+l)/2;

    pll l1 = query(2*node, l, mid, lq, rq);
    pll r1 = query(2*node+1, mid+1, r, lq, rq);

    ll bstpx = max(l1.F, l1.S+r1.F);;
    ll sm = l1.S+r1.S;
    return {bstpx, sm}; 

}


void solve(){

    ll n, q; cin >> n >> q;

    cf(i,1,n){
        cin >> arr[i];
    }


    build(1, 1, n);

    ll t, l ,r;
    f(i,0,q){
        cin >> t >> l >> r;
        if(t==1){
            update(1, 1, n, l, r);
        } else {
            cout << max({query(1, 1, n, l, r).F, query(1, 1, n, l, r).S, 0ll}) << "\n";   
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

