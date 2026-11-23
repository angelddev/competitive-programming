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
 

    vll alphabet(27);

    ll n; cin >> n;
    string s; cin >> s;

    ll ans = 0;
    vpl ranges;
    f(i,0,n/2){
        if(s[i]!=s[(n-1)-i]){
            ranges.pb({min(s[(n-1)-i], s[i]), max(s[i], s[(n-1)-i])});
        } 
    }
    sort(all(ranges));

    if(ranges.empty()){
        cout << "0\n";
        return;
    }
    ll start = ranges[0].F, nd = ranges[0].S;
    f(i,1,ranges.size()){
        ll x = ranges[i].F, y = ranges[i].S;
        if(x > nd){
            ans+=(nd-start);
            start = x; nd = y; 
        } 
        nd = max(y, nd);
    }
    ans+=(nd-start);

    cout << ans << "\n";


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; cin >> t;
    while(t--){
        solve(); 
    }
}

