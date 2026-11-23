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

    string arr; cin >> arr;

    ll cont = 0;
    ll ans = 0;
    
    while(cont < n){
        ll flag = 1;
        ll cont2 = cont;
        
        while(cont2 < n && cont2 < cont + k){ 
            if(arr[cont2] == '0') {
                flag = 0;
                break;
            }
            cont2++;
        }

        cont += k; 
        
        if(flag){
            ans++;
        }
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

