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
ll hotels[8*100005];
pll tree[8*100005];

void build(ll node, ll l, ll r){
    if(l==r){
        tree[node]={hotels[l], l};
        return;
    }
    ll mid=(r+l)/2;
    build(2*node, l, mid);
    build(2*node+1, mid+1, r);

    tree[node]=max(tree[2*node],tree[2*node+1]);
}

void update(ll node, ll l, ll r, ll pos, ll val){
    if(l==r){
        tree[node]={val, l};
        return;
    }
    ll mid=(r+l)/2;
    if(pos<=mid){
        update(2*node, l, mid, pos, val);
    } else update(node*2+1, mid+1, r, pos, val);

    tree[node]=max(tree[2*node],tree[2*node+1]);
}

pll query(ll node, ll l, ll r, ll ql, ll qr, ll mn){
    if(tree[node].F<mn){
        return {0, -1};
    }
    if(l==r){
        return tree[node];
    }
    ll mid=(r+l)/2;
    if(tree[node*2].F>=mn) return query(2*node, l, mid, ql, qr, mn);
    else return query(2*node+1, mid+1, r, qr, ql, mn);
}

void solve(){

    ll n, q; cin >> n >> q;

    f(i,0,n){
        cin >> hotels[i];
    }
    build(1, 0, n-1);
    vll group(q);
    f(i,0,q){
        cin >> group[i];
    }

    for(ll g: group){
        ll mn=g;
        pll a= query(1, 0, n-1, 0, n-1, g);
        if(a.S==-1) cout << 0 << " "; else{
            cout << a.S+1 << " ";
            update(1, 0, n-1, a.S, a.F-g);
        }
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t=1; 
    while(t--){
        solve(); 
    }
}