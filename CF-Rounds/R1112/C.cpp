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
    ll n; 
    cin >> n;

    vll l(n+1), r(n+1), u(n+1), v(n+1);
    cf(i, 1, n){
        cin >> l[i] >> r[i] >> u[i] >> v[i];
    }

    rf(m, n, 1){

        ll count = 1; 
        cf(i, 1, n){
            if ((n-i+1)<(m-count+1)) {
                break;
            }
            ll lr = count;
            ll rr = m-count+1;
            if(!(lr>=l[i]&&lr<=r[i]) && !(rr>=u[i]&&rr<=v[i])){
                count++; 
            }
            if(count>m){
                break; 
            }
        }
        
        if(count > m){
            cout << m << "\n";
            return;
        }
    }

    cout << 0 << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t; cin >> t;
    while(t--){
        solve(); 
    }
}