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
 
ll tree[8*100001];
ll nums[2*100001];
 
void build(ll node, ll l, ll r){
    if(l==r){
        tree[node]=nums[l];
        return;
    }
    ll mid=(l+r)/2;
    build(node*2, l, mid);
    build(node*2+1, mid+1, r);
 
    tree[node]=max(tree[node*2],tree[node*2+1]);
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
 
    return max(left, right);
}
 
void update(ll node, ll l, ll r, ll pos, ll val){
    if(l==r){
        tree[node]=val;
        return;
    }
    ll mid=(r+l)/2;
 
    if(pos<=mid){
        update(2*node, l, mid, pos, val);
    }
    else update(2*node+1, mid+1, r, pos, val);
    tree[node]=max(tree[node*2],tree[node*2+1]);
}
 
void solve(){
 
    ll n; cin >> n;
    vector<pll> info(n+1);
    cf(i,1,n){
        cin >> nums[i];
        cin >> info[i].F;
        cin >> info[i].S;
    }
    build(1, 1, n);

    vll dp(n+1000, 0);
    rf(i, n, 1){
        ll ans=query(1, 1, n, info[i].F+i, info[i].S+i);
        update(1, 1, n, i, nums[i]+ans);
        dp[i]=max(dp[i+1], nums[i]+ans);
    }
    cout << dp[1] << "\n";
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    //ll t; cin >> t;
    //while(t--)
        solve();
}