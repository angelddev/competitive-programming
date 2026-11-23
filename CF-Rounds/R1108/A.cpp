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
    vll ans(n+1);
    ll p=2;
    ll imp=1;
    cf(i,1,n){
        if(i%2==1){
            ans[i]=p;
            p+=2;
        } else {
            ans[i]=imp;
            imp+=2;
        }
    }

    for(ll i = 1; i <=n; i++){
        cout << ans[i] << " ";
    } cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t; cin >> t;
    while(t--){
        solve(); 
    }
}