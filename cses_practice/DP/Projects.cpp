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

    vector<pair<ll, pll>> arr(n);
    f(i,0,n){
        cin >> arr[i].S.F >> arr[i].F >> arr[i].S.S;
    }

    sort(all(arr));

    map<ll, ll> best;
    set<ll> covered;
    covered.insert(0);
    best[0] = 0;


    f(i,0,n){
        ll nd = arr[i].F, bg = arr[i].S.F, score = arr[i].S.S;
        covered.insert(nd);
        best[nd] = max({best[nd], score+best[*prev(covered.lower_bound(bg))], best[*prev(covered.lower_bound(nd))]});
    }

    ll ans = 0;
    for(auto v : best){
        //cout << v.F << " " << v.S << "\n";
        ans = max(v.S, ans);
    }

    cout << ans << "\n";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; //cin >> t;
    while(t--){
        solve(); 
    }
}

