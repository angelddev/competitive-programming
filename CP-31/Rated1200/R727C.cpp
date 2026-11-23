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
const ll mod = 1e9 + 7;
 
ll t, n, m, k, a, b, tot; 
 
void solve(){
   
    ll n, k, x; cin >> n >> k >> x;
    vll group(n);
    f(i,0,n) cin >> group[i];

    sort(group.begin(), group.end());
    vll diffs;
    f(i,1,n){
        if(group[i]-group[i-1]>x)
        diffs.pb(group[i]-group[i-1]);
    }

    if(diffs.size()==0){
        cout << 1 << "\n";
        return;
    }

    sort(diffs.begin(), diffs.end());

    ll sz=diffs.size();
    ll substract = 0;

    f(i,0,sz){
        if(k<(diffs[i]-1)/x)
        break; 
        k-= (diffs[i]-1)/x;
        substract++;
    }

    cout << max((ll)1, sz-substract+1) << "\n";

    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    //ll t; cin >> t;
  //  while(t--)
        solve();
}