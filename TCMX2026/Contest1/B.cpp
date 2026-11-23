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

vll ans;

void check(ll n, ll digits){

    ll copy = n;
    
    ll count = 1;
    while(count<digits){
        ll change = copy%10;
        copy/=10;
        copy+=(change*pow(10, digits-1));

        ll diff = copy-n;
        if(diff<=0) {
            count++;
            continue;
        }

        if(diff%digits==count) ans.pb(diff);
        count++;
    }


}

void solve(){

    ans.clear();
    ll n; cin >> n;

    ll digits = 0, copy = n;
    while(copy>0){
        copy/=10;
        digits++;
    }
    
    check(n, digits);

    sort(all(ans));
    cout << ans.size() << "\n";
    for(ll num : ans){
        cout << num << " ";
    } cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; cin >> t;
    while(t--){
        solve(); 
    }
}

