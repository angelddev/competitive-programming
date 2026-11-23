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
    
    vll arr(n+2);
    cf(i,1,n){
        cin >> arr[i];
    }

    vll ans(k+1);
    stack<pll> values;

    vll sfx(n+2), pfx(n+2);
    rf(i,n,1){
        sfx[i]=max(sfx[i+1], arr[i]);
    }

    cf(i,1,n){
        pfx[i] = max(pfx[i-1], arr[i]);
    }
    cf(i,1,n){
        ll mnl, mnr;
        mnl = lower_bound(pfx.begin()+1, pfx.begin()+n+1, arr[i])-pfx.begin();    
        mnr = upper_bound(sfx.begin()+1, sfx.begin()+n+1, arr[i], greater<ll>())-sfx.begin()-1;

        ll r = max({abs(mnr-mnl), abs(mnr-i)});
        ll l = max({abs(mnr-mnl), abs(mnl-i)});
        ll side = mnr-mnl+1;
        ans[arr[i]] = max(ans[arr[i]], 2*side);
    }

    cf(i,1,k)
    cout << ans[i] << " ";

    cout << "\n";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; cin >> t;
    while(t--){
        solve(); 
    }
}

