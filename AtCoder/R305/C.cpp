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


    vector<vector<char>> mat(n+2, vector<char>(m+2, '.'));
    cf(i,1,n){
        cf(j,1,m){
            cin >> mat[i][j];
        }
    }

    
    ll cont = 0, a = -1, b = -1;

    cf(i,1,n){
        cf(j,1,m){
            cont = 0;
            if(mat[i][j]=='.'){
            if(mat[i-1][j-1]=='#'){
                cont++;
            }
            if(mat[i-1][j]=='#'){
                cont++;
            }
            if(mat[i][j-1]=='#'){
                cont++;
            }if(cont>=3) {a = i, b = j;
            break;} else cont = 0;

            if(mat[i][j+1]=='#'){
                cont++;
            }
            if(mat[i+1][j+1]=='#'){
                cont++;
            }
            if(mat[i+1][j]=='#'){
                cont++;
            } if(cont>=3) {a = i, b = j;
            break;} else cont = 0;

            if(mat[i][j-1]=='#'){
                cont++;
            }
            if(mat[i+1][j]=='#'){
                cont++;
            }
            if(mat[i+1][j-1]=='#'){
                cont++;
            } if(cont>=3) {a = i, b = j;
            break;} else cont = 0;

            if(mat[i-1][j]=='#'){
                cont++;
            }
            if(mat[i-1][j+1]=='#'){
                cont++;
            }
            if(mat[i][j+1]=='#'){
                cont++;
            } if(cont>=3) {a = i, b = j;
            break;} else cont = 0;

            }
        }
    }

    cout << a << " " << b << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; //cin >> t;
    while(t--){
        solve(); 
    }
}

