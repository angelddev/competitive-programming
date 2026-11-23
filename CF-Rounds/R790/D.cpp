#include<bits/stdc++.h>
 
#define ll long long 
#define all(a) begin(a), end(a)
#define pll pair<ll, ll> 
#define vll vector<ll>
#define vvl vector<vll>
#define vpl vector<pll> 
#define f(i, s, e) for(ll i=s; i<e; i++)
#define cf(i, s, e) for(ll i=s; i<=e; i++)
#define rf(i, s, e) for(ll i=s; i>=e; i--) 
#define MOD(x) ((((x)%mod) + mod)%mod)
#define F first
#define S second
#define pb push_back 
using namespace std; 
typedef long double ld;
 
const ll INF = 1e18; 
const ll mod = 998244353;
 
ll t, n, m, k, a, b, tot; 
 
void solve(){
   
    ll n, m; cin >> n >> m;

    vvl board(n, vll(m));
    f(i,0,n){
        f(j,0,m){
            cin >> board[i][j];
        }
    }

    ll mx=0;
    f(i,0,n){
        f(j,0,m){
            ll upl=0, p=i-1, k=j-1;
            while(p>=0&&k>=0){
                upl+=board[p][k];
                p--; k--;
            }  
            ll upr=0; p=i-1, k=j+1;
            while(p>=0&&k<m){
                upr+=board[p][k];
                k++; p--;
            }  
            ll downr=0; p=i+1, k=j+1;
            while(p<n&&k<m){
                downr+=board[p][k];
                k++; p++;
            }  
            ll downl=0; p=i+1, k=j-1;
            while(p<n&&k>=0){
                downl+=board[p][k];
                k--; p++;
            } 
            mx = max(mx, upl + upr + downl + downr +board[i][j]);
        }
    }

    cout << mx << "\n";

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    ll t; cin >> t;
    while(t--)
        solve();
}