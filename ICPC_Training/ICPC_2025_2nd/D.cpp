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
ll sz[1000007];
ll parent[1000007];


void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
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


void solve(){

    ll n, m; cin >> n >> m;
    

    vvll adj(n+1);
    vpl val(n+1);
    vll ergy(n+1);
    cf(i,1,n){
        cin >> val[i].F;
        val[i].S=i;
        ergy[i]=val[i].F; 
        make_set(i);
    }

    ll x, y;
    f(i,0,m){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    sort(all(val));
    

    vll ans(n+1);
    vll temp;
    cf(i,1,val.size()-1){
        temp.push_back(val[i].S);

        for(ll num : adj[val[i].S]){
            if(ergy[num]<=val[i].F){
                union_sets(num, val[i].S);
            }
        }
        if(val.size()-1==i||val[i+1].F!=val[i].F){
            for(ll num : temp){
                ans[num]=sz[find_set(num)];
            }
            temp.clear();
        } else continue;
    }

    cf(i,1,n){
        cout << ans[i] << " ";
    }
    cout << "\n";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t=1;
    while(t--){
        solve(); 
    }
}