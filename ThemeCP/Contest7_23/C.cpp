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


    void solve(){
    

        ll n; cin >> n;
        map<ll, ll> deg;
        ll x, y;
        vvll adj(n+1);
        f(i,0,n-1){
            cin >> x >> y;
            adj[x].pb(y);
            adj[y].pb(x);
            deg[x]++;
            deg[y]++;
        }

        vll SONS(n+1);

        f(i,1,n+1)
        for(ll v : adj[i]){
            if(deg[v]==1) SONS[i]++;
        }

        ll leaves = 0, mx = 0, cand = 0, cont = 0;

        for(pll el : deg){
            if(el.S==1) leaves++;
            if(SONS[el.F]>SONS[cand]){
                mx = el.S;
                cand = el.F;
            } else if(SONS[el.F]==SONS[cand]){
                if(deg[el.F]>deg[cand]){
                    mx = el.S;
                    cand = el.F;
                }
            }
        }

        if(deg[cand]==1) leaves--;
        cout << leaves-SONS[cand] << "\n";

    }

    int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); 

        ll t = 1; cin >> t;
        while(t--){
            solve(); 
        }
    }

