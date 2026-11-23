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

void solve() {

    ll a, b, x;
    cin >> a >> b >> x;

    vll va, vb;

    while(true){
        va.pb(a);
        if(a==0) break;
        a/=x;
    }

    while(true){
        vb.pb(b);
        if(b==0) break;
        b/=x;
    }

    ll ans=INF;
    f(i,0,va.size()){
        f(j,0,vb.size()){
            ans = min(ans, i+j+abs(va[i]-vb[j]));
        }
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t; cin >> t;
    while(t--){
        solve(); 
    }
}