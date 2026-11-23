#include<bits/stdc++.h>
#define ll long long 
#define all(a) begin(a), end(a)
#define pll pair<ll, ll> 
#define vll vector<ll>
#define vvl vector<vll>
#define vpl vector<pll> 
#define f(i, s, e) for(ll i=s; i<e; i++)
#define cf(i, s, e) for(ll i=s; i<=e; i++)
#define rf(i, s, e) for(ll i=s; i>=e; i--) 
#define MOD(x) ((((x)%mod) + mod)%mod)
#define F first
#define S second
#define pb push_back 
using namespace std; 
typedef long double ld;
 
const ll INF = 1e18; 
const ll mod = 998244353;
 
vll tree;
string s;

void build(ll node, ll l, ll r){
    if(l==r){
        tree[node]=1<<(s[l]-'a');
        return;
    }
    ll mid=(l+r)/2;
    build(node*2, l, mid);
    build(node*2+1, mid+1, r);

    tree[node]=tree[node*2]|tree[node*2+1];
}
 
ll query(ll node, ll l, ll r, ll ql, ll qr){
    if(l>qr||r<ql){
        return 0;
    }
    if(ql<=l&&r<=qr){
        return tree[node];
    }
    ll mid=(r+l)/2;
    ll left = query(2*node, l, mid, ql, qr);
    ll right = query(2*node+1, mid+1, r, ql, qr);
    return left|right;
}
 
void update(ll node, ll l, ll r, ll pos, char val){
    if(l==r){
        tree[node]=1<<(val-'a');
        return;
    }
    ll mid=(r+l)/2;
 
    if(pos<=mid){
        update(2*node, l, mid, pos, val);
    }
    else update(2*node+1, mid+1, r, pos, val);
    tree[node]=tree[node*2]|tree[node*2+1];
}
 
void solve(){
 
    cin >> s;
    ll q; cin >>q;
    ll n; n=s.size()-1;
    tree.assign(4*n, 0);
    build(1, 0, n);
    ll type;
    f(i,0,q){
        cin >> type;
        if(type==2){
            ll a, b;
            cin >> a >> b;
            a--, b--;
            ll ans = query(1, 0, n, a, b);
            cout << __builtin_popcountll(ans) << "\n";
        } else {
            ll a; char b;
            cin >> a >> b;
            a--;
            update(1, 0, n, a, b);
        }
    }
    
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    //ll t; cin >> t;
    //while(t--)
        solve();
}