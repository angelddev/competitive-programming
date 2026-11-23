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
    vector<vector<char>> matrix(n, vector<char>(m));

    ll ei, ej;
    f(i,0,n){
        f(j,0,m){
            cin >> matrix[i][j];
            if(matrix[i][j]=='E'){
                ei=i, ej=j;
            }
        }
    }

    vector<vector<char>> answer(n, vector<char>(m, '?'));
    answer[ei][ej]='E';
    vvl checked(n, vll(m,0));
    queue<pll> bfs;
    bfs.push({ei,ej});
    vvl dist(n, vll(m,INF));
    dist[ei][ej]=0;
    while(!bfs.empty()){
    auto [x,y] = bfs.front(); bfs.pop();

    if(y<m-1 && matrix[x][y+1]=='.' && dist[x][y+1]==INF){
        dist[x][y+1] = dist[x][y] + 1;
        bfs.push({x, y+1});
    }
    if(x>0 && matrix[x-1][y]=='.' && dist[x-1][y]==INF){
        dist[x-1][y] = dist[x][y] + 1;
        bfs.push({x-1, y});
    }
    if(y>0 && matrix[x][y-1]=='.' && dist[x][y-1]==INF){
        dist[x][y-1] = dist[x][y] + 1;
        bfs.push({x, y-1});
    }
    if(x<n-1 && matrix[x+1][y]=='.' && dist[x+1][y]==INF){
        dist[x+1][y] = dist[x][y] + 1;
        bfs.push({x+1, y});
    }
}


    ll q; cin >> q;
    ll x, y;
    f(i,0,q){
        cin >> x >> y;
        x--, y--;
        if(matrix[x][y]=='X'){
            cout << "X\n";
            continue;
        }
        if(matrix[x][y]=='#'){
            cout << "W\n";
            continue;
        }
        if(matrix[x][y]=='E'){
            cout << "E\n";
            continue;
        }

        if(y>0 && dist[x][y-1] == dist[x][y]-1) cout << "L\n";
        else if(x<n-1 && dist[x+1][y] == dist[x][y]-1) cout << "D\n";
        else if(y<m-1 && dist[x][y+1] == dist[x][y]-1) cout << "R\n";
        else if(x>0 && dist[x-1][y] == dist[x][y]-1) cout << "U\n";
        else cout << "?\n";
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    //ll t; cin >> t;
    //while(t--)
        solve();
}