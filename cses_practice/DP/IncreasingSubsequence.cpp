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

ll st[900000];

void update(ll node, ll l, ll r, ll pos, ll val){
    if(l==r) {
        st[node] = val;
        return;
    }

    ll mid = (l+r)/2;
    if(pos<=mid){
        update(2*node, l, mid, pos, val);
    } else update(2*node+1, mid+1, r, pos, val);

    st[node]=max(st[2*node], st[2*node+1]);
}

ll query(ll node, ll l, ll r, ll lq, ll rq){
    
    if(l>=lq&&r<=rq) return st[node];

    if(l>rq||r<lq) return 0;

    ll mid = (l+r)/2;
    return max(query(2*node, l, mid, lq, rq), query(2*node+1, mid+1, r, lq, rq));
}

void solve(){
    
    ll n; cin >> n;

    vll nums(n);
    f(i,0,n){
        cin >> nums[i]; 
    }

    ll cont = 1;
    map<ll, ll> rep;
    set<ll> uniq;
    f(i,0,n){
        uniq.insert(nums[i]);
    }

    for(ll nu : uniq){
        rep[nu] = cont++;
    }

    f(i,0,n){
        ll val = query(1, 0, n, 0, rep[nums[i]]-1);
        update(1, 0, n, rep[nums[i]], val+1);
    }

    cout << query(1, 0, n, 0, n) << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; //cin >> t;
    while(t--){
        solve(); 
    }
}

