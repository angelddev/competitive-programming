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

vvll vis;
vpl modes = {{0, 1}, {1, 0}, {1, 1}, {-1, 0}, {0, -1}, {-1, -1}, {1, -1}, {-1, 1}};
ll n, m;
ll best = INF;
pll bestSpot = {-1, -1};

void bfsProb(ll x, ll y, ll dis, ll absX, ll absY){
    queue<pll> bfs;
    bfs.push({x, y});
    if(x>n||x<1||y<1||y>m) return;
    vis[x][y] = 1;
    while(!bfs.empty()){
        pll cords = bfs.front();
        bfs.pop();
        for(pll v : modes){
            pll temp = cords;
            temp.F+=v.F, temp.S+=v.S;
            ll man = abs(temp.F-absX)+abs(temp.S-absY);
            if(man > dis || temp.F>n || temp.S>m || temp.F == 0 || temp.S == 0 || vis[temp.F][temp.S]==1) continue;
            vis[temp.F][temp.S] = 1;
            bfs.push({temp.F, temp.S});
        }
    }
}

void solve(){
 
    ll k, h;
    cin >> n >> m >> k >> h;
    ll x1, y1; cin >> x1 >> y1;

    vis.assign(n+1, vll(m+1, 0));

    ll x, y, d;
    f(i,0,k){
        cin >> x >> y >> d;
        if(d==0){
            bfsProb(x, y, d, x, y);
            continue;    
        }
        bfsProb(x+(d-1), y, d, x, y);
        bfsProb(x-(d-1), y, d, x, y);
        bfsProb(x, y+(d-1), d, x, y);
        bfsProb(x, y-(d-1), d, x, y);
    }



    f(i,0,h){
        cin >> x >> y;
        if(vis[x][y]!=1)
        vis[x][y] = -1;
    }

    vpl modes2 = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    queue<pair<pll, ll>> bfs;
    bfs.push({{x1, y1}, 0});
    if(vis[x1][y1]==1){
        cout << "-1 -1\n";
        return;
    }
    while(!bfs.empty()){
        
        pll cords = bfs.front().F;
        ll cur = bfs.front().S;
        bfs.pop();

        if(vis[cords.F][cords.S]==-1){
            if(best>cur){
                best = cur;
                bestSpot = cords;
            } else if(best==cur){
                if(bestSpot.F<cords.F) continue;
                if(bestSpot.F==cords.F){
                    bestSpot.S = min(bestSpot.S, cords.S);
                } else {
                    bestSpot = cords;
                }
            }
            continue;
        }
        if(cur > best) break;

        for(pll v : modes2){
            pll temp = cords;
            temp.F+=v.F, temp.S+=v.S;
            if(temp.F>n || temp.S>m|| temp.F == 0 || temp.S == 0 || vis[temp.F][temp.S]==1) continue;
            if(vis[temp.F][temp.S]==0) vis[temp.F][temp.S]=1;
            bfs.push({{temp.F, temp.S}, cur+1});
        }
    }
    // cf(i,1,n){
    //     cf(j,1,m){
    //         cout << vis[i][j] << "  ";
    //     } cout << "\n\n";
    // }
    cout << bestSpot.F << " " << bestSpot.S << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);      

    ll t = 1; //cin >> t;
    while(t--){
        solve(); 
    }
}

