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
    multiset<ll> a;


    f(i,0,n){
        cin >> arr[i];
        a.insert(arr[i]);
    }
    
    if(arr[0]==0){
        if(arr[n-1]==0){
            cout << "0\n"; return;
        } else if(a.count(0)>1){ cout << "1\n"; return;}
    }
    
    else if(arr[n-1]==0){
        if(a.count(0)>1){ cout << "1\n"; return;}
    } else if(a.count(0)>1)cout << "2\n";
    else cout << "-1\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; cin >> t;
    while(t--){
        solve(); 
    }
}