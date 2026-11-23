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


void solve(){

    ll n; cin >> n;
    vector<vector<char>> mat(n, vector<char>(n));

    f(i,0,n){
        f(j,0,n){
            cin >> mat[i][j];
        }
    }

    ll ans=0;
    for(ll i = 0; i<n/2; i++){
        vector<char> temp;
        for(ll j = i; j<n-1-i; j++){
            char mx='a';
            temp.push_back(mat[i][j]);
            temp.push_back(mat[j][n-1-i]);
            temp.push_back(mat[n-1-i][n-1-j]);
            temp.push_back(mat[n-1-j][i]);
            for(char l : temp){
                mx=max(l, mx);
            }
            for(char l : temp){
                ans+=(mx-l);
            }
            temp.clear();
        }
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t; cin >> t; 
    while(t--){
        solve(); 
    }
}