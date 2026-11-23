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

    ll n, m, q; cin >> n >> m >> q;
    vector<vector<pair<long double, ll>>> adj(n+1);
    ll x, y;
    long double w;
    f(i,0,m){
        cin >> x >> y >> w;
        adj[x].pb({-1*log10(w/100), y});
        
    }

    f(i,0,q){
        ll a, b, t;
        cin >> a >> b >> t;

        priority_queue<pair<long double, ll>, vector<pair<long double, ll>>, greater<pair<long double, ll>>> pq;
        pq.push({0.0, a});

        vector<long double> dis(n+1, INF);
        dis[a]=0;

        while(!pq.empty()){
            long double w = pq.top().F;
            ll n = pq.top().S;
            pq.pop();
            if(w>dis[n]) continue;

            for(auto e : adj[n]){
                if(e.F+w<dis[e.S]){
                    pq.push({e.F+w, e.S});
                    dis[e.S]=e.F+w;
                }
            }
        }

        if(dis[b]==INF){
            cout << "0\n";
            continue;
        }
        long double rl = -dis[b]; 
        long double loss = pow(10, rl);

        long double ans = loss*t;

        cout <<fixed<<setprecision(10)<< ans<<"\n";
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