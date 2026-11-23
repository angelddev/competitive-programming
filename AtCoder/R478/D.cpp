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
 
    ll n, q;
    cin >> n >> q;

    vector<vll> mp(n+4);
    map<ll, ll> freqs;
    ll cont = 0;

    ll x, l , r;
    f(i,0,q){
        cin >> l >> r >> x;
        mp[l].pb(x);
        mp[r+1].pb(-x);
    }

    cf(i,1,n){
        f(j,0,mp[i].size()){
            if(mp[i][j]>0){
                freqs[mp[i][j]]++;
                if(freqs[mp[i][j]]==1) cont++;
            }
            else{
                freqs[-mp[i][j]]--;
                if(freqs[-mp[i][j]]==0) cont--;
            }
        }

        cout << cont << " ";
    } cout << "\n";


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; //cin >> t;
    while(t--){
        solve(); 
    }
}

