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

    ll n; cin >> n;

    vll nums(n);
    f(i,0,n){
        cin >> nums[i];
    }

    if(n%2!=0){
        cout << "NO\n";
        return;
    }
    
    ll mn = INF, mx = 0;

    for(ll i=1; i<n; i+=2){
        mx = max(mx, nums[i]);
    }

    for(ll i=0; i<n; i+=2){
        mn = min(mn, nums[i]);
    }
    
    if(mx<mn-1){
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t; cin >> t;
    while(t--){
        solve(); 
    }
}