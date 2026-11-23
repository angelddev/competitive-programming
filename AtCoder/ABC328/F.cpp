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
    
    ll n, q; cin >> n >> q;

    vector<set<ll>> arr(n+1);
    ll x, y;

    f(i,0,n){
        cin >> x;
        arr[i].insert(x);
    }

    f(i,0,q){
        
        cin >> x >> y;
        x--, y--;

        if(arr[x].size()>arr[y].size()){     
        
            for(ll el : arr[y])
                arr[x].insert(el);
        
            swap(arr[x], arr[y]);
        } 
        
        else {
            for(ll el : arr[x])
                arr[y].insert(el);
        }
        arr[x].clear();

        cout << arr[y].size() << "\n";
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; //cin >> t;
    while(t--){
        solve(); 
    }
}

