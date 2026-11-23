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

ll arr[3000000];
ll st[9000000];

void build(ll node, ll l, ll r){

    if(l==r){
        st[node] = arr[l];
        return;
    }

    ll mid = (l+r)/2;

    build(node*2, l, mid);
    build(node*2+1, mid+1, r);

    st[node] = st[node*2]+st[node*2+1];

}

void update(ll node, ll l, ll r, ll pos, ll val){
    
    if(l==r){
        st[node] += val;
        return;
    }

    ll mid = (l+r)/2;

    if(pos<=mid){
        update(2*node, l, mid, pos, val);
    } else update(2*node+1, mid+1, r, pos, val);

    st[node] = st[node*2] +st[2*node+1];

}

ll query(ll node, ll l, ll r, ll lq, ll rq){
    
    if(l>=lq&&r<=rq){
        return st[node];
    }
    if(l>rq||r<lq){
        return 0;
    }

    ll mid = (l+r)/2;
    return query(2*node, l, mid, lq, rq)+query(2*node+1, mid+1, r, lq, rq);

}

vll sals;

ll get_pos(ll value){

    return lower_bound(all(sals), value)-sals.begin();
}

void solve(){

    ll n, q; cin >> n >> q;
    set<ll> un;
    vll vec;
    ll x,y;

    f(i,0,n){
        cin >> x;
        un.insert(x);
        vec.pb(x);
    }

    char c;
    vector<pair<char, pll>> queries;
    f(i,0,q){
        cin >> c >> x >> y;
        un.insert(x);
        un.insert(y);
        queries.pb({c, {x, y}});
    }

    ll cont = 0;
    for(ll e: un){
        sals.pb(e);
        cont++;
    }

    for(ll v : vec){
        arr[get_pos(v)]++;
    }

    build(1, 0, cont+1);

    
    for(pair<char, pll> qu : queries){
        char c = qu.F;
        ll x = qu.S.F;
        ll y = qu.S.S;
        if(c=='!'){
            update(1, 0, cont+1, get_pos(vec[x-1]), -1);
            update(1, 0, cont+1, get_pos(y), 1);
            vec[x-1] = y;
        } else {
            cout << query(1, 0, cont+1, get_pos(x), get_pos(y)) << "\n";
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

