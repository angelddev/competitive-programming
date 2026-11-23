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
    ll ans = 0;
    f(i,0,n){
        cin >> arr[i];
        ans+=arr[i];
    }

    sort(all(arr));

    vll disc(k);
    f(i,0,k){
        cin >> disc[i];
    }

    sort(all(disc));

    ll flag = 1;
    
    ll cont = 0;
    while(flag && k>0){
        k--;
        if(n-disc[cont]>=0){
            n-=disc[cont];
            cont++;
            ans-=arr[n];
        } else flag = 0;
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

