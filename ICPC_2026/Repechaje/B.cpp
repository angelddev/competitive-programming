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
ll n;

void solve(){
 
    ll m, q;
    cin >> n;

    vvll mat(n+1, vll(n+2));

    cf(i,1,n){
        cf(j,1,n){
            cin >> mat[i][j];
        }
    }
    cin >> m;

    vvll sm(n+2, vll(n+2));
    ll p, l, x, y, s;

    f(i,0,m){
        cin >> p >> l >> x >> y >> s;
        cf(k,min(p, x), max(p, x)){
            sm[k][min(l, y)]+=s;
            sm[k][max(l+1, y+1)]-=s;
        }
    }

    cf(i, 1, n){
        cf(j, 1, n){
            sm[i][j]+=sm[i][j-1];
        }
    }


    cf(i,1,n){
        cf(j,1,n){
            if(mat[i][j]==-1){
                mat[i][j]=INF;
            }
            else 
            if(i!=j)
            mat[i][j]+=sm[i][j];
        }
    }

    cf(k, 1, n) {
        cf(i, 1, n) {
            cf(j, 1, n) {
                if (mat[i][k] < INF && mat[k][j] < INF)
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]); 
            }
        }
    }

    cin >> q;

    f(i,0,q){
        cin >> x >> y;
        if(mat[x][y]==INF) cout << -1;
        else cout << mat[x][y];
        cout << "\n";
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; //cin >> t;
    while(t--){
        solve(); 
    }
}

