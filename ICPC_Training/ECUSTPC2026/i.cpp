
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
    ll n, m, k, mx=0;
    cin >> n >> m >> k;
    ll prof, p, q, t, s;
    f(i,0,n){
        cin >> p >> q >> t;
        prof = q-p;
        prof = prof*((k-1)/t);
        mx = max(mx, prof);
    }
    f(i,0,m){
        cin >> p >> q >> t >> s;
        prof = -p;
        prof = prof + q*(((k-1-t)/s)+1);
        mx = max(mx, prof );
    }
    cout << mx << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t; cin >> t;
    while(t--){
        solve(); 
    }
}