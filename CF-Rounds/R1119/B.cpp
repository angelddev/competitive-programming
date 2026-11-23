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

    vll arr(n);
    f(i,0,n){
        cin >> arr[i];
    }
    

    ll streak = 1;
    ll ans = 0, Sev = 0, Sod = 0, od = 0;
    f(i,0,n){
        if(arr[i]%2==1) od++;
        else if((arr[i]/2)%2) Sod++;
        else Sev++;
    }

    cout << max({Sev, Sod, od}) << "\n";


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; cin >> t;
    while(t--){
        solve(); 
    }
}

