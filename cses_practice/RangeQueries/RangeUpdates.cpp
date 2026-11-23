#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define vll vector<ll>
#define vpl vector<pll>
#define vvll vector<vll>
#define f(i, s, e) for(ll i=s; i<e; i++)
#define cf(i, s, e) for(ll i=s; i<=e; i++)
#define rf(i, s, e) for(ll i=s; i>=e; i--)
#define all(a) begin(a), end(a)
#define endl '\n'
#define pb push_back 
#define F first 
#define S second 
using namespace std; 

const ll INF = 1e18; 
const ll MOD = 1e9+7; 
ll arr[300005];
ll st[2000000];
ll tg_add[2000000];
ll tg_set[2000000];

void build(ll node, ll l, ll r){
    if(l==r){
        st[node] = arr[l];
        return;
    }

    ll mid = (l+r)/2;
    build(2*node, l, mid);
    build(2*node+1, mid+1, r);
    st[node] = st[2*node]+st[2*node+1];
}

void push(ll node, ll l, ll r){
    ll mid = (l+r)/2;
    if(tg_set[node] > 0){
        st[2*node]   = tg_set[node]*(mid-l+1);
        st[2*node+1] = tg_set[node]*(r-mid);
        tg_set[2*node]   = tg_set[node];
        tg_set[2*node+1] = tg_set[node];
        tg_add[2*node]   = 0;
        tg_add[2*node+1] = 0;
        tg_set[node] = 0;
    }

    st[2*node]       += tg_add[node]*(mid-l+1);
    st[2*node+1]     += tg_add[node]*(r-mid);
    tg_add[2*node]   += tg_add[node];
    tg_add[2*node+1] += tg_add[node];
        
    tg_add[node] = 0;
}

void update1(ll node, ll l, ll r, pll ran, ll val){

    if(l>=ran.F&&r<=ran.S){
        tg_add[node] += val;
        st[node] += val*((r-l)+1);
        return;
    }

    if(l>ran.S||r<ran.F) return;

    ll mid = (l+r)/2;
    push(node, l, r);
    update1(2*node, l, mid, ran, val); 
    update1(2*node+1, mid+1, r, ran, val);
    st[node] = st[2*node]+st[2*node+1];
}

void update2(ll node, ll l, ll r, pll ran, ll val){

    if(l>=ran.F&&r<=ran.S){
        tg_set[node] = val;
        tg_add[node] = 0;
        st[node] = val*((r-l)+1);
        return;
    }

    if(l>ran.S||r<ran.F) return;

    ll mid = (l+r)/2;
    push(node, l, r);
    update2(2*node, l, mid, ran, val); 
    update2(2*node+1, mid+1, r, ran, val);
    st[node] = st[2*node]+st[2*node+1];
}

ll query(ll node, ll l, ll r, ll lq, ll rq){

    if(l>=lq&&r<=rq){
        return st[node];
    }

    if(l>rq||r<lq) return 0;

    ll mid = (l+r)/2;
    push(node, l, r);
    ll val1 = query(2*node, l, mid, lq, rq); 
    ll val2 = query(2*node+1, mid+1, r, lq, rq);
    return val1+val2;
}

void solve(){

    ll n, q; cin >> n >> q;

    cf(i,1,n){
        cin >> arr[i];
    }

    build(1, 1,n);
    ll t, x, y, w;
    f(i,0,q){
        cin >> t;
        if(t==1){
            cin >> w >> x >> y;
            update1(1, 1, n, {w, x}, y);
        } else if(t==2){
            cin >> w >> x >> y;
            update2(1, 1, n, {w, x}, y);
        } else {
            cin >> w >> x;
            cout << query(1, 1, n, w, x) << "\n";
        }
    }

    
}

int main(){
    #ifdef DEBUG
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout); 
    #else 
        ios_base::sync_with_stdio(0); 
        cin.tie(NULL); 
    #endif 

    ll t=1;
    //cin>>t; 
    while(t--){
        solve(); 
    }
}