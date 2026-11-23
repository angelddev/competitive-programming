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
ll tree[500006];
ll arr[100007];

void build(ll node, ll l, ll r){
    if(l==r){
        tree[node] = arr[l];
        return;
    }

    ll mid = (l+r)/2;
    build(2*node, l, mid);
    build(2*node+1, mid+1, r);

    tree[node]= max(tree[node*2], tree[node*2+1]);
}

void update(ll node, ll l, ll r, ll pos, ll val){
    if(l==r){
        tree[node] = val;
        return;
    }

    ll mid = (l+r)/2;
    if(pos<=mid)
    update(2*node, l, mid, pos, val);
    else
    update(2*node+1, mid+1, r, pos, val);

    tree[node]= max(tree[node*2], tree[node*2+1]);
}

ll query(ll node, ll l, ll r, ll val, ll idx){

    if(l==r){
        if(tree[node]<val){
            return -1;
        } else return l;
    }

    ll mid = (l+r)/2;
    ll fb = -1;
    if(tree[node*2]>=val&&mid>=idx){
        fb = query(2*node, l, mid, val, idx);
    }
    if(fb==-1) 
        return query(2*node+1, mid+1, r, val, idx);
    else return fb;
    

}



void solve(){

    ll n, q; cin >> n >> q;

    f(i,0,n){
        cin >> arr[i];
    }

    build(1, 0, n-1);

    ll t, v1, v2;
    f(i,0,q){
        cin >> t >> v1 >> v2;
        if(t==1){
            update(1, 0, n-1, v1, v2);
        }else {
            cout << query(1, 0, n-1, v1, v2) << "\n";
        }
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
