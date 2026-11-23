#include<bits/stdc++.h>
 
#define ll long long 
#define all(a) begin(a), end(a)
#define pll pair<ll, ll> 
#define vll vector<ll>
#define vvl vector<vll>
#define vpl vector<pll> 
#define f(i, s, e) for(ll i=s; i<e; i++)
#define cf(i, s, e) for(ll i=s; i<=e; i++)
#define rf(i, s, e) for(ll i=s; i<e; i--)
#define MOD(x) ((((x)%mod) + mod)%mod)
#define F first
#define S second
#define pb push_back 
using namespace std; 
typedef long double ld;
 
const ll INF = 1e18; 
const ll mod = 1e9 + 7;
 
ll t, n, m, k, a, b, tot; 

void solve(){

    int n; cin >> n;
    vector<long long> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vll prefixNoSign(n);
    vll prefixSubstract(n, 0);

    prefixNoSign[0]=arr[0];
    f(i,1,n){
        prefixNoSign[i]=prefixNoSign[i-1]+abs(arr[i]);
    }

    f(i,1,n){
        prefixSubstract[i]=prefixSubstract[i-1]+arr[i];
    }

    ll mx;
    f(i,0,n){
        if(i==0){
            mx=prefixSubstract[n-1]*-1;
            continue;
        }
        if(i==n-1){
            mx=max(mx, prefixNoSign[n-2]);
            continue;
        }
        ll left=prefixNoSign[i-1];
        ll right=-1*(prefixSubstract[n-1]-prefixSubstract[i]);
        mx=max(mx, left+right);

    }

    cout << mx << "\n";


}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        solve();
    }
}