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

    queue<pair<pll, ll>> bfs;
    bfs.push({{1, 1}, 0});

    vpl cords;
    cords.pb({2, 1});
    cords.pb({2, -1});
    cords.pb({-2, 1});
    cords.pb({-2, -1});
    cords.pb({1, 2});
    cords.pb({1, -2});
    cords.pb({-1, 2});
    cords.pb({-1, -2});

    vvll ans(n+2, vll(n+2, -1));
    while(!bfs.empty()){
        ll x = bfs.front().F.F;
        ll y = bfs.front().F.S;
        ll dis = bfs.front().S;
        bfs.pop();

        ans[x][y] = dis;

        for(pll cor : cords){
            if(x+cor.F>n||x+cor.F<1||y+cor.S>n||y+cor.S<1||ans[x+cor.F][y+cor.S]!=-1) continue;
            bfs.push({{x+cor.F, y+cor.S}, dis+1});
            ans[x+cor.F][y+cor.S] = dis+1;
        }
    }


    cf(i, 1, n){
        cf(j, 1, n){
            cout << ans[i][j] << " ";
        } cout << "\n";
    }
    


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; //cin >> t;
    while(t--){
        solve(); 
    }
}

