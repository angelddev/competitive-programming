#include<bits/stdc++.h>
 
#define ll long long 
#define all(a) begin(a), end(a)
#define pll pair<ll, ll> 
#define vll vector<ll>
#define vvl vector<vll>
#define vpl vector<pll> 
#define f(i, s, e) for(ll i=s; i<e; i++)
#define cf(i, s, e) for(ll i=s; i<=e; i++)
#define rf(i, s, e) for(ll i=s; i>=e; i--) 
#define MOD(x) ((((x)%mod) + mod)%mod)
#define F first
#define S second
#define pb push_back 
using namespace std; 
typedef long double ld;
 
const ll INF = 1e18; 
const ll mod = 998244353;

void solve(){

    ll n, k; cin >> n >> k;
    vpl movies(n);
    multiset<ll> free;
    f(i,0,n){
        cin >> movies[i].S >> movies[i].F;
    }
    sort(all(movies));

    ll ans=0;
    f(i,0,k){
        free.insert(0);
    }

    f(i,0,n){
        auto it= free.upper_bound(movies[i].S);
        if(it==free.begin())
            continue;
        else {
            free.erase(--it);
            free.insert(movies[i].F);
            ans++;
        }
    }

    cout << ans << "\n";

}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    //ll t; cin >> t;
    //while(t--)
        solve();
}