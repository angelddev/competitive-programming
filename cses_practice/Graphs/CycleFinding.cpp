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

struct Edge{
    ll a, b, cost;
};

void solve(){

    ll n, m; cin >> n >> m;

    ll x1, y, weight;
    vector<Edge> edges;
    f(i,0,m){
        cin >> x1 >> y >> weight;
        Edge e;
        e.a=--x1, e.b=--y, e.cost=weight;
        edges.pb(e);
    }

    vll d(n, INF);
    vll p(n, -1);
    d[0]=0;
    ll x;
    f(i,0,n){
        x=-1;
        for(Edge e:edges){
            if(d[e.b]>d[e.a]+e.cost){
                d[e.b] = d[e.a] + e.cost;
                p[e.b]=e.a;
                x=e.b;
            }
        }
    }

    if(x==-1){
        cout << "NO\n";
        return;
    }

    int y1 = x;
    vll ans;
    for (int i = 0; i < n; ++i)
        y1 = p[y1];

    ll start = y1;

    do {
        ans.pb(y1);
        y1 = p[y1];
    } while (y1 != start);

    ans.pb(start);
    reverse(all(ans));

    cout << "YES\n";
    f(i,0,ans.size()){
        cout << ans[i]+1 << " ";
    }cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t=1; 
    while(t--){
        solve(); 
    }
}