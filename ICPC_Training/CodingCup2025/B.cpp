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


void solve(){

    ll n, m; cin >> n >> m;

    vvll adj(n+1);
    ll x, y;
    f(i,0,m){
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    vll visited1(n+1), visited2(n+1);

    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq1;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq2;
    vpl odd, even;
    ll cont=2;
    for(ll i=3;i<=n;i+=2){
        odd.pb({cont++, i});
    }
    cont=2;
    for(ll i=4;i<=n;i+=2){
        even.pb({cont++, i});
    }
    reverse(all(odd));
    reverse(all(even));

    ll mx=1;
    pq1.push({1, 1});
    while(!pq1.empty() || !odd.empty()){
        if (!odd.empty() && (pq1.empty() || odd.back().F == pq1.top().F)) {
            auto [w, u] = odd.back();
            odd.pop_back();
    
            if (visited1[u] == 0) {
                pq1.push({w, u});
            }
            continue; 
        }
        auto [d, u] = pq1.top(); pq1.pop();
        
        if(visited1[u] == 1) continue;
        visited1[u] = 1;
        mx = max(mx, d);

        for(auto e : adj[u]){
            if(visited1[e] == 0){
                pq1.push({d+1, e});
            }
        }
    }

    ll mx2 = 1;
    pq2.push({1, 2}); 
    while(!pq2.empty() || !even.empty()){
        if (!even.empty() && (pq2.empty() || even.back().F == pq2.top().F)) {
            auto [w, u] = even.back();
            even.pop_back();
            if (visited2[u] == 0) {
                pq2.push({w, u});
            }
            continue;
        }
        auto [d, u] = pq2.top(); pq2.pop();
        
        if(visited2[u] == 1) continue;
        visited2[u] = 1;
        mx2 = max(mx2, d);

        for(auto e : adj[u]){
            if(visited2[e] == 0){
                pq2.push({d+1, e});
            }
        }
    }

    ll band=0;
    f(i,1,n+1){
        if(visited1[i]==0){
            band=1;
            break;
        }
    }
    if(band==1)
        cout << -1 << "\n";
    else cout << min(mx, mx2) << "\n";
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t=1; 
    while(t--){
        solve(); 
    }
}