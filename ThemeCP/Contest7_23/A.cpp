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


    ll n, k; cin >> n >> k;
    k = (n*n)-k;
    if(k==1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
 
    vector<vector<char>> mat(n+2, vector<char>(n+2, 'P'));
    ll cont = 0;
    f(i,0,n){
        f(j,0,n){
            if(cont==k) break;
            cont++;
            if(i==0){
                mat[i][j]='L';
            } else mat[i][j] = 'U';
        }
    }
    if(k!=0) mat[0][0] = 'R';
    f(i,0,n){
        f(j,0,n){
            if(mat[i][j]=='P') mat[i][j] = 'R';
        }
    }

    f(i,0,n){
        f(j,0,n){
            cout << mat[i][j];
        } cout << "\n";
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; cin >> t;
    while(t--){
        solve(); 
    }
}

