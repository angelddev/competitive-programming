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

    vll arr(n), sorted(n);
    f(i,0,n){
        cin >> arr[i];
        sorted[i] = arr[i];
    }

    sort(all(sorted));

    ll idx = -1;
    f(i,0,n){
        if(arr[i]!=sorted[i]){
            idx = i;
            break;
        }
    }

    if(idx==-1){
        cout << "Yes\n";
        return;
    }

    f(i,idx+k,n){
        if(arr[i]!=sorted[i]){
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; //cin >> t;
    while(t--){
        solve(); 
    }
}

