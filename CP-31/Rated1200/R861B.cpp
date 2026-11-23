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
 
ll t, n, m, k, a, b, tot; 

void solve(){

    ll n, m; cin >> n >> m;

    vector<vector<ll>> arr(m, vector<ll>(n));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[j][i];
        }
    }

    f(i,0,m){
        sort(arr[i].begin(), arr[i].end());
    }

    ll ans=0;
    f(i,0,m){
        f(j,0,n){
            ans+=-(arr[i][j]*((n-1)-j))+(arr[i][j]*j);
        }
    }

    cout << ans << "\n";



}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    ll t; cin >> t;
    while(t--)
    solve();
}