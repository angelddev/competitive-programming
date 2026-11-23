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
    if(node == parent[node]) return node;

    return parent[node] = find_set(parent[node]);
}

void make_union(ll a, ll b){
    a=find_set(a);
    b=find_set(b);

    if(a==b) return;
    
    if(sz[a]<sz[b]) swap(a, b);

    sz[a]+=sz[b];
    parent[b]=a;
}

struct Edge{
    ll u; ll v; ll cost;
};

ll EdgeSort(Edge a, Edge b){
    return a.cost<b.cost;
}

void solve(){

    ll n, m; cin >> n >> m;
    sz.assign(n+1, 0);
    parent.assign(n+1, 0);
    cf(i,1,n) make_set(i);

    vector<Edge> Edges;
    f(i,0,m){
        ll uT, vT, costT;
        cin >> uT >> vT >> costT;
        Edge temp;
        temp.u=uT; temp.v=vT; temp.cost=costT;
        Edges.pb(temp);
    }

    sort(all(Edges), EdgeSort);

    ll sum = 0;
    for(Edge e : Edges){
        if(find_set(e.u)!=find_set(e.v)){
            sum+=e.cost;
            make_union(e.u, e.v);
        }
    }

    ll lookFor = find_set(1);
    cf(i,1,n){
        if(lookFor!=find_set(i)) {
            cout << "IMPOSSIBLE\n"; return;
        }
    }

    cout << sum << "\n";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t=1;
    while(t--){
        solve(); 
    }
}