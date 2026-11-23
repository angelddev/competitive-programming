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

vll diag1, diag2, cols;
vector<vector<char>> board;
ll ans=0;

void dfs(ll row){
    if(row==8){
        ans++; return;
    }

    f(i,0,8){
        if(board[row][i]=='*') continue;
        if(cols[i]==1||diag1[row-i+7]==1||diag2[row+i]==1){
            continue;
        } 
        cols[i]=diag1[row-i+7]=diag2[row+i]=1;
        dfs(row+1);
        cols[i]=diag1[row-i+7]=diag2[row+i]=0;
    }
}


void solve(){

    board.assign(8, vector<char>(8));
    diag1.assign(10000, 0);
    diag2.assign(10000, 0);
    cols.assign(8, 0);
    f(i,0,8){
        f(j,0,8){
            cin >> board[i][j];
        }
    }
    dfs(0);
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t=1; 
    while(t--){
        solve(); 
    }
}