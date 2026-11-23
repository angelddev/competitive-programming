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
vll parent;
vll sz;
vll parent2;
vll sz2;


void make_set(ll node){
    parent[node]=node;
    sz[node]=1;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

void make_set2(ll node){
    parent2[node]=node;
    sz2[node]=1;
}

int find_set2(int v) {
    if (v == parent2[v])
        return v;
    return parent2[v] = find_set2(parent2[v]);
}

void union_sets2(int a, int b) {
    a = find_set2(a);
    b = find_set2(b);
    if (a != b) {
        if (sz2[a] < sz2[b])
            swap(a, b);
        parent2[b] = a;
        sz2[a] += sz2[b];
    }
}

void solve(){

    ll n, m1, m2;
    cin >> n >> m1 >> m2;
    vvll adj(n+1);
    parent.assign(n+1, 0);
    sz.assign(n+1, 1);
    parent2.assign(n+1, 0);
    sz2.assign(n+1, 1);

    cf(i,1,n){
        make_set(i);
        make_set2(i);
    }

    ll x, y;
    f(i,0,m1){
        cin >> x >> y;
        adj[x].pb(y);
    }

    f(i,0,m2){
        cin >> x >> y;
        union_sets2(x, y);
    }

    ll ans=0;
    cf(i,1,n)
    for(ll node : adj[i]){
        if(find_set2(node)!=find_set2(i)){
            ans++;
        } else union_sets(node, i);
    }


    vll check(n+1, 0);
    ll compF=0;
    cf(i, 1, n){
        if(check[find_set(i)]==0){
            compF++;
            check[find_set(i)]=1;
        }
    }

    vll check1(n+1, 0);
    ll compG=0;
    cf(i, 1, n){
        if(check1[find_set2(i)]==0){
            compG++;
            check1[find_set2(i)]=1;
        }
    }
    
    ans+=(compF-compG);
    cout << ans << "\n";


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t; cin >> t; 
    while(t--){
        solve(); 
    }
}