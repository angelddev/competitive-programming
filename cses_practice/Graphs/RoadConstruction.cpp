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
const int LOG = 19;

vll sz;
vll parent;

void make_set(ll node){
    sz[node]=1;
    parent[node]=node;
}

ll find_set(ll node){
    if(node==parent[node]) return node;
    return parent[node] = find_set(parent[node]); 
}

void union_set(ll a, ll b){
    a=find_set(a);
    b=find_set(b);
    if(sz[a]<sz[b]) swap(a, b);
    if(a==b) return;

    sz[a]+=sz[b];
    parent[b]=a;
}


void solve(){

    ll n, m; cin >> n >> m;

    sz.assign(n+1, 0);
    parent.assign(n+1, 0);
    
    cf(i,1,n) make_set(i);
    ll x, y;
    ll componentsAmount=n;
    ll mxSz=1;
    f(i,0,m){
        cin >> x >> y;
        if(find_set(x)!=find_set(y)){
            componentsAmount--;
        }
        union_set(x, y);
        ll pr=find_set(x);

        mxSz=max(mxSz, sz[pr]);

        cout << componentsAmount << " " << mxSz << "\n";
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