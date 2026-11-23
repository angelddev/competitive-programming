
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
vll sizes;

void make_set(ll v){
    parent[v]=v;
    sizes[v]=1;
}

ll find_set(ll node){
    if(parent[node]==node){
        return node;
    }
    return parent[node]=find_set(parent[node]);
}

ll union_sets(ll a, ll b){
    a=find_set(a);
    b=find_set(b);
    if(a!=b){
        if(sizes[a]<sizes[b])
            swap(a, b);
        parent[b]=a;
        sizes[a]+=sizes[b];
        return 1;
    }
    else return 0;
}


void solve(){

    ll n; cin >> n;
    
    parent.assign(n+1, 0);
    sizes.assign(n+1, 0);

    cf(i,1,n){
        make_set(i);
    }

    ll x, y;
    vpl cycles, connections;
    f(i,0,n-1){
        cin >> x >> y;
        if(!union_sets(x, y)) cycles.pb({x, y});
    }
    
    
    cf(i,1,n){
        cf(j,i+1,n){
            if(union_sets(i, j)==1) connections.pb({i, j});
        }
    }

    cout << cycles.size() << "\n";
    f(i, 0, cycles.size()){
        cout << cycles[i].F << " " << cycles[i].S << " " <<  connections[i].F << " " <<  connections[i].S << "\n";
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