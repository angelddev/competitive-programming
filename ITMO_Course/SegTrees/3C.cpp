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
ll tree[900007];

void update(ll node, ll l, ll r, ll pos){
    if(l==r){
        tree[node]^=1;
        return;
    }

    ll mid = (l+r)/2;
    if(pos<=mid){
        update(2*node, l, mid, pos);
    } else {
        update(2*node+1, mid+1, r, pos);
    }

    tree[node]=tree[node*2]+tree[node*2+1];
}

ll query(ll node, ll l, ll r, ll lq, ll rq){

    if(l>=lq&&r<=rq){
        return tree[node];
    }
    if(l>rq||r<lq){
        return 0;
    }

    ll mid = (l+r)/2;
    return query(node*2, l, mid, lq, rq)+query(node*2+1, mid+1, r, lq, rq);

}

void solve(){

    ll n; cin >> n;

    vpl fq(n+1, {-1, -1});
    vll starts;
    ll x;
    f(i,0,2*n){
        cin >> x;
        if(fq[x].F==-1){
            starts.pb(x);
            fq[x].F=i;
        } else {
            update(1, 0, 2*n, i);
            fq[x].S=i;
        }
    }

    vll ans(n+1);

    f(i,0,n){
        ans[starts[i]]=query(1, 0, 2*n, 0, fq[starts[i]].S-1);
        update(1, 0, 2*n, fq[starts[i]].S);
    }

    f(i,1,n+1){
        cout << ans[i] << " ";
    } cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t=1;
    while(t--){
        solve(); 
    }
}
