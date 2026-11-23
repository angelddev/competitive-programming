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

    vll pfx(n);
    cin >> pfx[0];
    f(i,1,n){
        cin >> pfx[i];
        pfx[i]+=pfx[i-1];
    }

    map<ll, ll> mp;
    mp[0]=1;
    ll ans = 0;
    f(i,k,n){
        ans+=mp[pfx[i]%k];
        mp[pfx[i-k]%k]++;
       // cout << i << " " << ans << "\n";
    }

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

