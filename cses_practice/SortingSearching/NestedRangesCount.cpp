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

ll st1[900000];
ll st2[900000];

void update(ll node, ll l, ll r, ll pos){

    if(l==r){
        st1[node]++;
        return;
    }

    ll mid = (l+r)/2;
    if(pos<=mid){
        update(2*node, l, mid, pos);
    } else update(2*node+1, mid+1, r, pos);

    st1[node] = st1[2*node]+st1[2*node+1];
}

ll query(ll node, ll l , ll r, ll lq, ll rq){

    if(l>=lq&&r<=rq){
        return st1[node];
    }
    if(l>rq||r<lq){
        return 0;
    }

    ll mid = (l+r)/2;
    return query(2*node, l, mid, lq, rq)+query(2*node+1, mid+1, r, lq, rq);
}

void update2(ll node, ll l, ll r, ll pos){

    if(l==r){
        st2[node]++;
        return;
    }

    ll mid = (l+r)/2;
    if(pos<=mid){
        update2(2*node, l, mid, pos);
    } else update2(2*node+1, mid+1, r, pos);

    st2[node] = st2[2*node]+st2[2*node+1];
}

ll query2(ll node, ll l , ll r, ll lq, ll rq){

    if(l>=lq&&r<=rq){
        return st2[node];
    }
    if(l>rq||r<lq){
        return 0;
    }

    ll mid = (l+r)/2;
    return query2(2*node, l, mid, lq, rq)+query2(2*node+1, mid+1, r, lq, rq);
}

bool ord(pair<pll, ll> a, pair<pll, ll> b){
    if(a.F.F<b.F.F){
        return true;
    } else if(a.F.F>b.F.F){
        return false;
    } else {
        if(a.F.S>b.F.S){
            return true;
        } else return false;
    }
}

ll mx = 200000;

void solve(){
    
    ll n; cin >> n;

    vector<pair<pll, ll>> ranges(n);
    f(i,0,n){
        cin >> ranges[i].F.F >> ranges[i].F.S;
        ranges[i].S=i;
    }

    sort(all(ranges), ord);

    vll inside(n);
    vll outside(n);

    set<ll> uniq;

    f(i,0,n){
        uniq.insert(ranges[i].F.S);
    }

    map<ll, ll> compressed;
    ll cur = 0;
    for (ll val : uniq) {
        compressed[val] = cur++;
    }
    
    f(i,0,n){
        outside[ranges[i].S] = query2(1, 0, mx, compressed[ranges[i].F.S], mx);
        update2(1, 0, mx, compressed[ranges[i].F.S]);
    }

    rf(i, n-1, 0){ 
        inside[ranges[i].S] = query(1, 0, mx, 0, compressed[ranges[i].F.S]);
        update(1, 0, mx, compressed[ranges[i].F.S]);
    }

    f(i,0,n){
        cout << inside[i] << " ";
    } cout << "\n";

    f(i,0,n){
        cout << outside[i] << " ";
    } cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; //cin >> t;
    while(t--){
        solve(); 
    }
}

