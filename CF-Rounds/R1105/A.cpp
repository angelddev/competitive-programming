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

    ll n, k; cin >> n >> k;

    vll arr(k, 0);

    ll pot=0, i=0, sum=0;
    while(true){
        if(sum+(1ll<<pot)>n) break;
        arr[i%k]+=(1ll<<pot);
        sum+=(1ll<<pot);
        i++;
        if(i%k==0) pot++;
    }

    ll ans=0;
    f(i,0,k){
        ans+=__builtin_popcount(arr[i]);
    }
    
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t; cin >> t;
    while(t--){
        solve(); 
    }
}