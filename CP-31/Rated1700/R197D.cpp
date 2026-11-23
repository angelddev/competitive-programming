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
 
vpl tree;
vll nums;

void build(ll node, ll l, ll r){
    if(l==r){
        tree[node]={nums[l], 0};
        return;
    }
    ll mid=(l+r)/2;
    build(node*2, l, mid);
    build(node*2+1, mid+1, r);

    ll check = 1^tree[node*2].S;
    if(check==1){
        tree[node]={tree[node*2].F|tree[node*2+1].F, check};
    } else tree[node]={tree[node*2].F^tree[node*2+1].F, check};
}
 
void update(ll node, ll l, ll r, ll pos, ll val){
    if(l==r){
        tree[node]={val, 0};
        return;
    }
    ll mid=(r+l)/2;
 
    if(pos<=mid){
        update(2*node, l, mid, pos, val);
    }
    else update(2*node+1, mid+1, r, pos, val);
    ll check = 1^tree[node*2].S;
    if(check==1){
        tree[node]={tree[node*2].F|tree[node*2+1].F, check};
    } else tree[node]={tree[node*2].F^tree[node*2+1].F, check};
}
 
void solve(){
 
    ll n, q; cin >> n >> q;
    ll N=1<<n;
    nums.assign(N, 0);
    f(i,0,N) cin >> nums[i];
    tree.assign(4*N, {0,0});
    build(1, 0, N-1);
    ll type, a, b;
    f(i,0,q){
        cin >> a >> b;
        a--;
        update(1, 0, N-1, a, b);
        cout << tree[1].F << "\n";
    }
    
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    //ll t; cin >> t;
    //while(t--)
        solve();
}