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

    ll n;
    cin >> n;

    if(n==1){
        cout << 1 << "\n";
        return;
    }
    if(n==2){
        cout << -1 << "\n";
        return;
    }
    vll ans(n);
    ans[0]=1; ans[1]=2;
    ans[2]=3;

    f(i,3,n){
        ans[i]=ans[i-1]*2;
    }
    for(ll i : ans){
        cout << i << " ";
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