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



void solve(){

    ll n; cin >> n;
    vll vessels(n);
    f(i,0,n){
        cin >> vessels[i];
    }

    vll ans;
    f(i,0,n){
        vll temp1(n), temp2(n);

        ll mx=0;
        f(j,1,n){
            ll prv= (i+j-1)%n;
            mx=max(mx, vessels[prv]);
            ll cr=(i+j)%n;
            temp1[cr]=mx;
        }
        mx=0;
        f(j,1,n){
            ll cr=(i-j+n)%n;
            mx=max(mx, vessels[cr]);
            temp2[cr]=mx;
        }

        ll sum = 0;
        f(j,0,n){
            sum+=min(temp1[j], temp2[j]);
        }

        ans.pb(sum);
    }

    for(ll n : ans){
        cout << n << " ";
    }
    cout << "\n";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t; cin >> t;
    while(t--){
        solve(); 
    }
}