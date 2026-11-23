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
 

    ll n, m; cin >> n >> m;

    vector<vector<char>> mat(n+2, vector<char>(m+2));
    cf(i,1,n){
        cf(j,1,m){
            cin >> mat[i][j];
        }
    }

    
    vpl RowSizes(n+2);
    cf(i,1,n){
        ll temp = 0;
        ll sz = 0;
        cf(j,1,m){
            if(mat[i][j]!='.') temp++;
            if(mat[i][j]=='U'||mat[i][j]=='D') sz++;
        }

        if(temp%2){
            cout << "-1\n";
            return;
        }

        RowSizes[i] = {sz/2, sz/2};
    }

    vpl ColumnSizes(m+2);
    cf(j,1,m){
        ll temp = 0;
        ll sz = 0;
        cf(i,1,n){
            if(mat[i][j]!='.') temp++;
            if(mat[i][j]=='L'||mat[i][j]=='R') sz++;
        }

        if(temp%2){
            cout << "-1\n";
            return;
        }

        ColumnSizes[j] = {sz/2, sz/2};
    }

    //row assignment
     vector<vector<char>> ans(n+2, vector<char>(m+2, '.'));
    cf(i,1,n){
        if(RowSizes[i].F>0||RowSizes[i].S>0){
            cf(j,1,m){
                if(mat[i][j]=='U'){
                    if(RowSizes[i].S>RowSizes[i].F){
                        ans[i][j] = 'B';
                        ans[i+1][j] = 'W';
                        RowSizes[i].S--;
                        RowSizes[i+1].F--;
                    } else {
                        RowSizes[i].F--;
                        RowSizes[i+1].S--;
                        ans[i][j] = 'W';
                        ans[i+1][j] = 'B';
                    }
                    mat[i+1][j] = '.';
                }
            }
        }
    }


    cf(j,1,m){
        if(ColumnSizes[j].F>0||ColumnSizes[j].S>0)
            cf(i,1,n){
                if(mat[i][j]=='L'){
                    if(ColumnSizes[j].S>ColumnSizes[j].F){
                        ColumnSizes[j].S--;
                        ColumnSizes[j+1].F--;
                        ans[i][j]='B';
                        ans[i][j+1] = 'W';
                    } else {
                        ColumnSizes[j].F--;
                        ColumnSizes[j+1].S--;
                        ans[i][j]='W';
                        ans[i][j+1] = 'B';
                    }

                    mat[i][j+1] = '.';
                }
            }
    }

    cf(i,1,n){
        cf(j,1,m){
            cout << ans[i][j];
        }
        cout << "\n";
    }

    //cout << " \n\n";


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; cin >> t;
    while(t--){
        solve(); 
    }
}

