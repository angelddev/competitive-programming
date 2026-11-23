#include <bits/stdc++.h>

typedef long long ll;

#define endl '\n'
#define sz(x) int((x).size())
#define all(a) begin(a), end(a)
#define pll pair<ll , ll>
#define vb vector<bool>
#define vll vector <ll>
#define vvll vector <vector<ll>>
#define vpl vector<pair<ll , ll>>
#define f(i, s, e) for(ll  i=s; i<e; i++)
#define cf(i, s, e) for(ll i=s;i<=e;i++)
#define rf(i, s, e) for(ll i=s;i>=e;i--)
#define MOD(x) ((((x)%mod)+ mod )%mod)
#define F first 
#define S second
#define pb push_back
using namespace std;
typedef long double ld;



void solve(){
    
    ll n, m; cin >> n >> m;

    vector<string> s(n+1);
    f(i,0,n){
        cin >> s[i];
    }

    
    vvll vis(n, vll(m, 0));

    ll ans = 0;
    f(i,0,n){
        f(j,0,m){
            if(!vis[i][j]&&s[i][j]!='0'){
                ans++;
                char c = s[i][j];
                queue<pll> bfs;
                
                bfs.push({i, j});
                while(!bfs.empty()){
                    ll x = bfs.front().F;
                    ll y = bfs.front().S;
                    bfs.pop();
                    vis[x][y] = 1;
                    
                    if(vis[max(0ll,x-1)][max(0ll,y-1)]==0ll&&s[max(0ll,x-1)][max(0ll,y-1)]==c){
                        bfs.push({max(0ll,x-1), max(0ll,y-1)});
                        vis[max(0ll,x-1)][max(0ll,y-1)] = 1;
                    }
                    if(vis[max(0ll,x-1)][min(m-1,y+1)]==0ll&&s[max(0ll,x-1)][min(m-1,y+1)]==c){
                        bfs.push({max(0ll,x-1), min(m-1,y+1)});
                        vis[max(0ll,x-1)][min(m-1,y+1)] = 1;
                    }
                    if(vis[max(0ll,x-1)][y]==0ll&&s[max(0ll,x-1)][y]==c){
                        bfs.push({max(0ll,x-1), y});
                        vis[max(0ll,x-1)][y] = 1;
                    }
                    if(vis[x][min(m-1,y+1)]==0ll&&s[x][min(m-1,y+1)]==c){
                        bfs.push({x, min(m-1,y+1)});
                        vis[x][min(m-1,y+1)] = 1;
                    }
                    if(vis[x][max(0ll,y-1)]==0ll&&s[x][max(0ll,y-1)]==c){
                        bfs.push({x, max(0ll,y-1)});
                        vis[x][max(0ll,y-1)] = 1;
                    }
                    if(vis[min(n-1,x+1)][max(0ll,y-1)]==0ll&&s[min(n-1,x+1)][max(0ll,y-1)]==c){
                        bfs.push({min(n-1,x+1), max(0ll,y-1)});
                        vis[min(n-1,x+1)][max(0ll,y-1)] = 1;
                    }
                    if(vis[min(n-1,x+1)][y]==0ll&&s[min(n-1,x+1)][y]==c){
                        bfs.push({min(n-1,x+1), y});
                        vis[min(n-1,x+1)][y] = 1;
                    }
                    if(vis[min(n-1,x+1)][min(m-1,y+1)]==0ll&&s[min(n-1,x+1)][min(m-1,y+1)]==c){
                        bfs.push({min(n-1,x+1), min(m-1,y+1)});
                        vis[min(n-1,x+1)][min(m-1,y+1)] = 1;
                    }
                }

            }
        }
    }

    cout << ans << "\n";




}


int main()
{
    #ifdef DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t=1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}
