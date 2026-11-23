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

    ll l = 0, r = n-1;

    ll ans = 0, sum = 0;
    f(i,0,5){
        sum+=arr[i];
    }
    ans^=sum;

    while(r<n-1){
        r++;
        sum-=arr[l];
        sum+=arr[r];
        l++;
        ans^=sum;
    }

    cout << sum << "\n";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; //cin >> t;
    while(t--){
        solve(); 
    }
}

