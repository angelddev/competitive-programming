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

void update(ll node, ll l , ll r, ll val){

    if(l==r){
        tree[node]=1;
        return;
    }
    ll mid = (l+r)/2;
    if(val<=mid){
        update(2*node, l, mid, val);
    } else update(2*node+1, mid+1, r, val);

    tree[node] = tree[node*2]+tree[node*2+1];
}

ll query(ll node, ll l, ll r, ll lq, ll rq){

    if(l>=lq&&r<=rq){
        return tree[node];
    }
    if(l>rq||r<lq) return 0;

    ll mid = (l+r)/2;
    return query(2*node, l, mid, lq, rq)+query(2*node+1, mid+1, r, lq, rq);

}

void solve(){
    
    ll n; cin >> n;

    ll x;
    f(i,0,n){
        cin >> x;
        cout << query(1, 0, n, x+1, n) << "\n";
        update(1, 0, n, x);
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
