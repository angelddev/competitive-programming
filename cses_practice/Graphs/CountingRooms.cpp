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
 
ll t, n, m, k, a, b, tot; 
 
void solve(){
   
    ll n, m; cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    vvl checked(n, vll(m, 0));

    f(i,0,n){
        f(j,0,m){
            cin >> grid[i][j];
        }
    }

    ll rooms=0;
    f(i,0,n){
        f(j,0,m){
            if(checked[i][j]==0&&grid[i][j]=='.'){
                checked[i][j]=1;
                rooms++;
                queue<pll> bfs;
                bfs.push({i,j});
                while(!bfs.empty()){
                    auto[x, y] = bfs.front();
                    bfs.pop();
                    if(x!=n-1&&checked[x+1][y]==0&&grid[x+1][y]=='.'){
                        bfs.push({x+1, y});
                        checked[x+1][y]=1;
                    }
                    if(y!=m-1&&checked[x][y+1]==0&&grid[x][y+1]=='.'){
                        bfs.push({x, y+1});
                        checked[x][y+1]=1;
                    }
                    if(x!=0&&checked[x-1][y]==0&&grid[x-1][y]=='.'){
                        bfs.push({x-1, y});
                        checked[x-1][y]=1;
                    }
                    if(y!=0&&checked[x][y-1]==0&&grid[x][y-1]=='.'){
                        bfs.push({x, y-1});
                        checked[x][y-1]=1;
                    }

                }
            }
        }
    }

    cout << rooms << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    //ll t; cin >> t;
    //while(t--)
        solve();
}