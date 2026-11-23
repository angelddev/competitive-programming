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

    ll sm = 0;
    vll arr(3*n, 0);
    f(i,0,n){
        cin >> arr[i];
    }

    
    ll act = 0;
    vll pfx(3*n);
    rf(i,n-1, 0){
        arr[i]=arr[i]+(act-pfx[i+k+1]);
        act+=arr[i];
        pfx[i] = act;
        sm+=arr[i];
        //cout << act << "\n";
    }

    if(sm%2){
        cout << "Alice\n";
    } else cout << "Bob\n";
    
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; cin >> t;
    while(t--){
        solve(); 
    }
}

