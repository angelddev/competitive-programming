#include<bits/stdc++.h>
#define ll long long 
#define all(a) begin(a), end(a)
#define pll pair<ll, ll> 
#define vll vector<ll>
#define vvl vector<vll>
#define vpl vector<pll> 
#define f(i, s, e) for(ll i=s; i<e; i++)
#define cf(i, s, e) for(ll i=s; i<=e; i++)
#define rf(i, s, e) for(ll i=s; i<e; i--)
#define MOD(x) ((((x)%mod) + mod)%mod)
#define F first
#define S second
#define pb push_back 
using namespace std; 
typedef long double ld;
 
const ll INF = 1e18; 
const ll mod = 1e9 + 7;

void solve(){
    ll n, m; cin >> n >> m;

    vll coveredcols(m, 0);
    vll coveredrows(n,0);
    vvl mat(n, vll(m));
    ll mx=0;

    f(i,0,n)
        f(j,0,m) {
            cin>>mat[i][j];
            mx=max(mx, mat[i][j]);
        }

    ll count=0;
    f(i,0,n){
        f(j,0,m) {
            if(mat[i][j]==mx){
                coveredrows[i]++;
                count++;
            }
        }
    }

    f(j,0,m){
        f(i,0,n) {
            if(mat[i][j]==mx){
                coveredcols[j]++;
            }
        }
    }
    ll idxrow=0, idxcol=0;
    f(i,0,n){
        f(j,0,m) {
            ll inter=0;
            if(mat[i][j]==mx){
                inter=1;
            }
            if(count-(coveredcols[j]+coveredrows[i]-inter)==0){
                idxrow=i;
                idxcol=j;
                break;
            }
        }
    }

    f(i,0,n){
        f(j,0,m) {
            if(i==idxrow){
                mat[i][j]--;
            }
        }
    }

    f(j,0,m){
        f(i,0,n) {
            if(j==idxcol&&i!=idxrow){
                mat[i][j]--;
            }
        }
    }

    mx=0;
    f(i,0,n){
        f(j,0,m) {
            mx=max(mx, mat[i][j]);
        }
    }

    cout << mx << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    ll t; 
    cin >> t;
    while(t--)
        solve();
        
    return 0;
}