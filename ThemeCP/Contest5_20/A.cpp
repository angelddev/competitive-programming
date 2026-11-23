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
 
    ll n; cin >> n;

    ll kx, ky, qx, qy, cx, cy; cin >> qx >> qy >> kx >> ky  >> cx >> cy;

    if(kx>qx&&cx>qx){
        if(ky>qy&&cy>qy){
            cout << "YES\n";
             return;
        }
        if(ky<qy&&cy<qy){
            cout << "YES\n";
             return;
        }
    }

    if(kx<qx&&cx<qx){
        if(ky>qy&&cy>qy){
            cout << "YES\n";
             return;
        }
        if(ky<qy&&cy<qy){
            cout << "YES\n";
             return;
        }
    }

    cout << "NO\n";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1;// cin >> t;
    while(t--){
        solve(); 
    }
}

