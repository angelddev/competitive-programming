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
    
    vvll mat(n+1, vll(m+1)), vis(n+1, vll(m+1));
    vector<string> trash;
    string s;

    f(i,0,n){
        cin >> s;
        trash.pb(s);
    }

    f(i,0,n){
        f(j,0,m){
            mat[i][j] = (ll)(trash[i][j]-'0');
        }
    }


    f(i,0,n){
        f(j,0,m){

            ll cont = 0;
            if(mat[i][j]==1) cont++;
            if(mat[i][j+1]==1) cont++;
            if(mat[i+1][j+1]==1) cont++;
            if(mat[i+1][j]==1) cont++;
            if(cont == 3){
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; cin >> t;
    while(t--){
        solve(); 
    }
}

