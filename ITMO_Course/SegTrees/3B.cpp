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

void update(ll node, ll l , ll r, ll pos){
    if(l==r){
        tree[node]^=1;
        return;
    }

    ll mid = (l+r)/2;

    if(pos<=mid){
        update(2*node, l, mid, pos);
    } else update(2*node+1, mid+1, r, pos);

    tree[node] = tree[node*2]+tree[node*2+1];
}

ll query(ll node, ll l, ll r, ll pos){
    if(l==r){
        return l;
    }

    ll mid = (l+r)/2;
    if(pos<=tree[node*2]){
        return query(2*node, l, mid, pos);
    } else return query(2*node+1, mid+1, r, pos-tree[2*node]);
}

void solve(){
    ll n; 
    cin >> n;

    vll order(n+1);

    cf(i,1,n){
        update(1, 1, n, i);
    }

    f(i,0,n){
        cin >> order[i];
    }

    ll cont = n;
    vll ans;
    rf(i,n-1,0){
        ll val = query(1, 1, n, cont-order[i]);
        ans.pb(val);
        update(1, 1, n, val);
        cont--;
    }

    rf(i, n-1, 0){
        cout << ans[i] << " ";
    } cout << "\n";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1;
    while(t--){
        solve(); 
    }
}
