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
const int LOG = 30;

void solve(){

    ll n, m; cin >> n >> m;

    ll up[n+1][LOG];
    ll x;
    cf(i,1,n){
        cin >> x;
        up[i][0]=x; 
    }

    f(i,1,LOG){
        cf(j,1,n){
            up[j][i]=up[up[j][i-1]][i-1];
        }
    }

    f(i,0,m){
        ll y;
        cin >> x >> y;
        f(j,0,LOG){
            if(y & (1<<j)) x = up[x][j];
        }
        cout << x << "\n";
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t=1;
    while(t--){
        solve(); 
    }
}