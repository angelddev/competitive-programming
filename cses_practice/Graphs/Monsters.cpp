#include <bits/stdc++.h>

#define ll long long 
#define endl '\n'
#define all(a) (a).begin(), (a).end()
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

const ll INF = 1e9;
const ll MOD = 1e9 +7;

ll t, n, m, k, a, b; 

void solve(){

    cin >> n >> m;
    vector<vector<char>> lab(n, vector<char>(m));
    pll man;
    queue<pair<pll, ll>> bfs;
    vvll mat(n, vll(m, -1));
    f(i,0,n){
        f(j,0,m){
            cin >> lab[i][j];
            if(lab[i][j]=='M'){
                bfs.push({{i,j}, 0});
                mat[i][j]=0;
            } else if(lab[i][j]=='A') man={i, j};
        }
    }

    while(!bfs.empty()){
        auto fr=bfs.front(); bfs.pop();
        if(fr.F.F!=n-1){
            if(lab[fr.F.F+1][fr.F.S]!='#'&&mat[fr.F.F+1][fr.F.S]==-1){
                bfs.push({{fr.F.F+1, fr.F.S}, fr.S+1});
                mat[fr.F.F+1][fr.F.S]=fr.S+1;
            }     
        } 
        if(fr.F.F!=0){
            if(lab[fr.F.F-1][fr.F.S]!='#'&&mat[fr.F.F-1][fr.F.S]==-1){
                bfs.push({{fr.F.F-1, fr.F.S}, fr.S+1});
                mat[fr.F.F-1][fr.F.S]=fr.S+1;
            }     
        } 
        if(fr.F.S!=m-1){
            if(lab[fr.F.F][fr.F.S+1]!='#'&&mat[fr.F.F][fr.F.S+1]==-1){
                bfs.push({{fr.F.F, fr.F.S+1}, fr.S+1});
                mat[fr.F.F][fr.F.S+1]=fr.S+1;
            }     
        } 
        if(fr.F.S!=0){
            if(lab[fr.F.F][fr.F.S-1]!='#'&&mat[fr.F.F][fr.F.S-1]==-1){
                bfs.push({{fr.F.F, fr.F.S-1}, fr.S+1});
                mat[fr.F.F][fr.F.S-1]=fr.S+1;
            }     
        } 
    }

    vector<vector<char>> backtrack(n, vector<char>(m, 'I'));
    backtrack[man.F][man.S]='H';
    bfs.push({man, 0});
    ll band=0;
    pll end;
    while(!bfs.empty()){
        auto fr=bfs.front(); bfs.pop();
        if(fr.F.F==n-1||fr.F.S==m-1||fr.F.S==0||fr.F.F==0){
            band=1;
            end={fr.F.F, fr.F.S};
            break;
        }
        if(lab[fr.F.F+1][fr.F.S]!='#'&&backtrack[fr.F.F+1][fr.F.S]=='I'&&(mat[fr.F.F+1][fr.F.S]>fr.S+1||mat[fr.F.F+1][fr.F.S]==-1)){
            bfs.push({{fr.F.F+1, fr.F.S}, fr.S+1});
            backtrack[fr.F.F+1][fr.F.S]='D';
        }
        if(lab[fr.F.F-1][fr.F.S]!='#'&&backtrack[fr.F.F-1][fr.F.S]=='I'&&(mat[fr.F.F-1][fr.F.S]>fr.S+1||mat[fr.F.F-1][fr.F.S]==-1)){
            bfs.push({{fr.F.F-1, fr.F.S}, fr.S+1});
            backtrack[fr.F.F-1][fr.F.S]='U';
        }
        if(lab[fr.F.F][fr.F.S+1]!='#'&&backtrack[fr.F.F][fr.F.S+1]=='I'&&(mat[fr.F.F][fr.F.S+1]>fr.S+1||mat[fr.F.F][fr.F.S+1]==-1)){
            bfs.push({{fr.F.F, fr.F.S+1}, fr.S+1});
            backtrack[fr.F.F][fr.F.S+1]='R';
        }
        if(lab[fr.F.F][fr.F.S-1]!='#'&&backtrack[fr.F.F][fr.F.S-1]=='I'&&(mat[fr.F.F][fr.F.S-1]>fr.S+1||mat[fr.F.F][fr.F.S-1]==-1)){
            bfs.push({{fr.F.F, fr.F.S-1}, fr.S+1});
            backtrack[fr.F.F][fr.F.S-1]='L';
        }
    }

    if(band==0){
        cout << "NO\n";
        return;
    }

    vector<char> ans;
    while(backtrack[end.F][end.S]!='H'){
        ans.pb(backtrack[end.F][end.S]);
        if(backtrack[end.F][end.S]=='R'){
            end.S--;
        } else 
        if(backtrack[end.F][end.S]=='L'){
            end.S++;
        } else 
        if(backtrack[end.F][end.S]=='D'){
            end.F--;
        } else
        if(backtrack[end.F][end.S]=='U'){
            end.F++;
        }
    }
    reverse(all(ans));
    cout << "YES\n" << ans.size() << "\n";
    f(i,0,ans.size()){
        cout << ans[i];
    } cout << "\n";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    t=1; 
    while(t--){
        solve(); 
    }
}