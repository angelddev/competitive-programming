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

    vll deg(n+1);
    ll x, y;
    f(i,0,m){
        cin >> x >> y;
        deg[x]++;
        deg[y]++;
    }

    ll falg = 0;
    cf(i,1,n){
        if(!deg[i]){
            cout << "Brain Melt\n";
            return;
        }
        if(deg[i]==n-1&&falg==0) falg = 1;
        else if(deg[i]!=1) falg = -1;
    }

    if(falg==1) cout << 2 << "\n";
    else cout << "Many\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; cin >> t;
    while(t--){
        solve(); 
    }
}

