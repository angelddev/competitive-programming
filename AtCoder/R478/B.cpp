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
 
    ll n, k; cin >> n >> k;

    vll arr(n);
    f(i,0,n){
        cin >> arr[i];
    }

    ll mx = 0;
    f(i,0,n){
        f(j,i+1,n){
            f(t,j+1,n){
                if(t+i+j+3>k) continue;
                mx = max(mx, arr[i]+arr[j]+arr[t]);
            }
        }
    }

    cout << mx << "\n";
    


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; //cin >> t;
    while(t--){
        solve(); 
    }
}

