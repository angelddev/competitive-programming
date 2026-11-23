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

    vector<vector<char>> directions(n, vector<char>(m));
    ll cordX=-1, cordY=-1;
    f(i,0,n){
        f(j,0,m){
            if(checked[i][j]==0&&grid[i][j]=='A'){
                checked[i][j]=1;
                queue<pll> bfs;
                bfs.push({i,j});
                while(!bfs.empty()){
                    if(cordX!=-1){
                        break;
                    }
                    auto[x, y] = bfs.front();
                    bfs.pop();
                    if(x!=n-1&&checked[x+1][y]==0&&grid[x+1][y]=='.'){
                        bfs.push({x+1, y});
                        directions[x+1][y]='D'; 
                        checked[x+1][y]=1;
                    }
                    if(y!=m-1&&checked[x][y+1]==0&&grid[x][y+1]=='.'){
                        bfs.push({x, y+1});
                        checked[x][y+1]=1;
                        directions[x][y+1]='R'; 
                    }
                    if(x!=0&&checked[x-1][y]==0&&grid[x-1][y]=='.'){
                        bfs.push({x-1, y});
                        checked[x-1][y]=1;
                        directions[x-1][y]='U'; 
                    }
                    if(y!=0&&checked[x][y-1]==0&&grid[x][y-1]=='.'){
                        bfs.push({x, y-1});
                        checked[x][y-1]=1;
                        directions[x][y-1]='L'; 
                    }
                    if(x!=n-1&&checked[x+1][y]==0&&grid[x+1][y]=='B'){
                        directions[x+1][y]='D';
                        cordX=x+1;
                        cordY=y; 
                    }
                    if(y!=m-1&&checked[x][y+1]==0&&grid[x][y+1]=='B'){
                        directions[x][y+1]='R'; 
                        cordX=x;
                        cordY=y+1;
                    }
                    if(x!=0&&checked[x-1][y]==0&&grid[x-1][y]=='B'){
                        directions[x-1][y]='U';
                        cordX=x-1;
                        cordY=y; 
                    }
                    if(y!=0&&checked[x][y-1]==0&&grid[x][y-1]=='B'){
                        directions[x][y-1]='L';
                        cordX=x;
                        cordY=y-1; 
                    }
                }
            }
        }
    }

    string path="";
    if(cordX==-1){
        cout << "NO" << "\n";
        return;
    }
    else {
        ll i=cordX, j=cordY;
        while(grid[i][j]!='A'){
            if(directions[i][j]=='D'){
                i--;
                path+='D';
            }
            if(directions[i][j]=='U'){
                i++;
                path+='U';
            }
            if(directions[i][j]=='L'){
                j++;
                path+='L';
            }
            if(directions[i][j]=='R'){
                j--;
                path+='R';
            }
        }
    }

    reverse(path.begin(), path.end());

    cout << "YES\n" << path.size() << "\n" << path << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    //ll t; cin >> t;
    //while(t--)
        solve();
}