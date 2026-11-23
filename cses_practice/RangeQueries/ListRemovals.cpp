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

ll arr[300005];
ll st[900005];

void build(ll node, ll l, ll r){

    if(l==r){
        st[node] = 1;
        return;
    }

    ll mid = (l+r)/2;
    
    build(2*node, l, mid);
    build(2*node+1, mid+1, r);
    
    st[node] = st[2*node]+st[2*node+1];

}

ll query(ll node, ll l, ll r, ll ith){

    if(l==r){
        return l;
    }

    ll mid = (l+r)/2;

    if(st[2*node]>=ith){
        return query(2*node, l, mid, ith);
    } else return query(2*node+1, mid+1, r, ith-st[2*node]);
}


void update(ll node, ll l, ll r, ll pos){
    
    if(l==r){
        st[node] = 0;
        return;
    }

    ll mid = (l+r)/2;
    if(pos<=mid){
        update(2*node, l, mid, pos);
    } else update(2*node+1, mid+1, r, pos);
    
    st[node] = st[2*node]+st[2*node+1];
}


void solve(){

    ll n; cin >> n;

    cf(i,1,n){
        cin >> arr[i];
    }
    build(1, 1, n);

    ll x;
    f(i,0,n){
        cin >> x;
        cout << arr[query(1, 1, n, x)] << "\n";
        
        update(1, 1, n, query(1, 1, n, x));
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

