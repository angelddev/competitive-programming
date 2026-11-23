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

    ll n, m; cin >> n >> m;

    vector<vector<char>> mat(n, vector<char>(m));
    f(i,0,n){
        f(j,0,m){
            cin >> mat[i][j];
        }
    }

    vvll vis(n, vll(m, INF));

    ll Hx, Hy; cin >> Hx >> Hy;
    ll Fx, Fy; cin >> Fx >> Fy;

    ll ins; cin >> ins;
    vector<string> instructions(ins);
    f(i,0,ins){
        cin >> instructions[i];
    }

    priority_queue<pair<ll, pll>, vector<pair<ll, pll>>, greater<pair<ll, pll>>> cords;
    cords.push({0, {Hx, Hy}});
    vis[Hx][Hy]=0;     
    if(mat[Hx][Hy]=='1'){
        cout << "-1\n";
        return;
    }
    
    while(!cords.empty()){
        auto c = cords.top();
        cords.pop();

        if(c.F > vis[c.S.F][c.S.S]) continue;

        for(string s : instructions){
            ll x=c.S.F, y=c.S.S, mov=0;
            for(char ch : s){
                if(ch=='D'){
                    if(x<n-1&&mat[x+1][y]=='0'){
                        x++;
                        mov++;
                    }
                }
                if(ch=='U'){
                    if(x>0&&mat[x-1][y]=='0'){
                        x--;
                        mov++;
                    }
                }
                if(ch=='L'){
                    if(y>0&&mat[x][y-1]=='0'){
                        y--;
                        mov++;
                    }
                }
                if(ch=='R'){
                    if(y<m-1&&mat[x][y+1]=='0'){
                        y++;
                        mov++;
                    }
                }
            }
            if(vis[x][y]>c.F+mov){
                vis[x][y]=c.F+mov;
                cords.push({c.F+mov, {x,y}});
            }
        }
    }

    if(vis[Fx][Fy]==INF)
    cout << "-1\n"; else 
    cout << vis[Fx][Fy] << "\n";
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t=1;
    while(t--){
        solve(); 
    }
}