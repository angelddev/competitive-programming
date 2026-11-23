#include<bits/stdc++.h>
 
#define ll long long 
#define all(a) begin(a), end(a)
#define pll pair<ll, ll> 
#define vll vector<ll>
#define vvl vector<vll>
#define vpl vector<pll> 
#define f(i, s, e) for(ll i=s; i<e; i++)
#define cf(i, s, e) for(ll i=s; i<=e; i++)
#define rf(i, s, e) for(ll i=s; i>=e; i--) 
#define MOD(x) ((((x)%mod) + mod)%mod)
#define F first
#define S second
#define pb push_back 
using namespace std; 
typedef long double ld;
 
const ll INF = 1e18; 
const ll mod = 998244353;

void solve(){
   
    ll n, m; cin >> n >> m;
    vvl adj(n+1);
    ll x, y;
    f(i,0,m){
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    queue<ll> bfs;
    vll checked(n+1, 0); checked[1]=1;
    vll parent(n+1);
    bfs.push(1);
    ll count=1, p;
    while(!bfs.empty()){
        p=bfs.front();
        if(p==n){
            break;
        }
        bfs.pop();
        for(ll son : adj[p]){
            if(checked[son]==0){
                checked[son]=1;
                parent[son]=p;
                bfs.push(son);
            }
        }
    }

    vll ans;
    if(p==n){
        ll num=p;
        while(num!=1){
            count++;
            ans.pb(num);
            num=parent[num];
        }
        ans.pb(num);
    }
    else{
        cout << "IMPOSSIBLE\n";
        return;
    }

    reverse(ans.begin(), ans.end());
    cout << count << "\n";
    for(ll num: ans)
        cout << num << " ";
    cout << "\n";

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    //ll t; cin >> t;
    //while(t--)
        solve();
}