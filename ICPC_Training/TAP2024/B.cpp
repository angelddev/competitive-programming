#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define vll vector<ll>
#define vpl vector<pll>
#define vvll vector<vll>
#define f(i,s,e) for(ll i=s; i<e; i++)
#define cf(i,s,e) for(ll i=s; i<=e; i++)
#define rf(i,s,e) for(ll i=s; i>=e; i--)
#define all(a) begin(a), end(a)
#define pb push_back
#define F first
#define S second
#define endl '\n'
using namespace std; 

const ll MOD = 1e9+7, INF = 1e18;

ll n, m, k; 

void solve(){

    ll n; cin >> n;

    vector<string> mat;
    string s;
    f(i,0,n){
        cin >> s;
        mat.pb(s);
    }

    ll ans = 0;
    f(i,0,n){
        f(j,0,n-1){
            if(mat[i][j]=='N'&mat[i][j+1]=='N'){
                ans++;
                mat[i][j+1]='B';
            }
        }
    }

    cout << ans << "\n";
    
}

int main(){
    #ifdef DEBUG 
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout);
    #else 
        ios_base::sync_with_stdio(0); 
        cin.tie(NULL); 
    #endif

    ll t=1;
    // cin>>t; 
    while(t--){
        solve(); 
    }
}