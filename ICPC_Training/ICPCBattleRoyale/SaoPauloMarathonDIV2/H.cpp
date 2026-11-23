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

    ll x, sum=0, band1=0, band2=0;
    f(i,0,n){
        cin >> x;
        if(x+sum>120&&band1==0){
            sum+=180;
            band1=1;
        }
        if(x+sum>720&&band2==0){
            sum+=180;
            band2=1;
        }
        sum+=x;
    }

    cout << sum << "\n";
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t=1;
    while(t--){
        solve(); 
    }
}