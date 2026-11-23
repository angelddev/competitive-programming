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
ll st[900005];
ll arr[300005];

void update(ll node, ll l, ll r, ll pos, ll val){

    if(l==r){
        st[node]+=val;
        return;
    }

    ll mid = (l+r)/2;
    if(pos<=mid){
        update(node*2, l, mid, pos, val);
    } else update(2*node+1, mid+1, r, pos, val);

    st[node] = st[2*node]+st[node*2+1];

}

ll query(ll node, ll l, ll r, ll lq, ll rq){

    if(l>=lq&&r<=rq){
        return st[node];
    } 
    if(l>rq||r<lq) return 0;

    ll mid = (l+r)/2;
    return query(2*node, l, mid, lq, rq)+query(2*node+1, mid+1, r, lq, rq);
    
}

void solve(){
    
    ll n, q; cin >> n >> q;


    cf(i,1,n){
        cin >> arr[i];
    }
   

    ll t, a, b, k;
    f(i,0,q){
        cin >> t;
        if(t==1){
            cin >> a >> b >> k;
            update(1, 1, n, a, k);
            if(b!=n)
            update(1, 1, n, b+1, -k);
        } else {
            cin >> k;
            cout << query(1, 1, n, 1, k)+arr[k] << "\n";
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

