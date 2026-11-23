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
    
    ll n, k, m; cin >> n >> k >> m;

    if(k>m){
        cout << "NO\n"; 
        return;
    }


    
    cout << "YES\n";
   f(i,0,n){
        if(i!=k-1)
        cout << 1 << " ";
        if(i==k-1){
            if(m>k){
                cout << m-(k-1) << " ";
            } else cout << 1 << " ";
        }
    } cout << "\n";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t; cin >> t;
    while(t--){
        solve(); 
    }
}