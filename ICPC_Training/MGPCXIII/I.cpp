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

void solve(){
    
    ll n, m, q;
    cin >> n >> m >> q;
    vvll lan(31, vll());
    vvll pLangs(n + 1, vll());
    ll c, x;
    f(i,0,n){
        cin >> c;
        f(j,0,c){
            cin >> x;
            lan[x].pb(i+1);
            pLangs[i+1].pb(x);
        }
    }

    vvll dis(33, vll(33, -1));
    cf(i,1,30){
        dis[i][i]=0;
    }

    cf(i,1,m){
        cf(j,i+1,m){
            queue<ll> que;
            que.push(i);
            vll d(m+1, -1);
            vll vis(31,0);
            d[i] = 0;
            ll ans = -1;
            while(!que.empty()){
                ll u = que.front();
                que.pop();

                if(u==j){
                    ans=d[j];
                    break;
                }
                for(ll l : lan[u]){
                    for(ll v : pLangs[l]){
                        if(d[v]==-1){
                            d[v]=d[u]+1;
                            que.push(v);
                        }
                    }
                }
            }
            dis[i][j]=ans;
            dis[j][i]=ans;
        }
    }


    f(i,0,q){
        ll x, y;
        cin >> x >> y;
    
        ll mn = INF;
        for(auto l : pLangs[x]){
            for(auto k : pLangs[y]){
                if(dis[l][k]==-1) continue;
                mn = min(mn, dis[l][k]);
            }
        }
        if(mn == INF) cout << -1 <<"\n"; else
        cout << mn << "\n";
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