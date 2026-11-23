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

void solve(){
    ll n; cin >> n;
    vll weight(n+1, 0);
    vll degree(n+1, 0);

    cf(i,1,n) cin >> weight[i];
    f(i,0,n-1){
        ll x, y; cin >> x >> y;
        degree[x]++;
        degree[y]++;
    }

    vll vals;
    cf(i,1,n){
        if(degree[i]>1)
        f(j,0,degree[i]-1){
            vals.pb(weight[i]);
        }
    }
    
    sort(vals.rbegin(), vals.rend());
    
    
    ll ans = accumulate(weight.begin(), weight.end(), 0ll);
    cout << ans << " ";
    f(i,0,n-2){
        cout << ans+vals[i] << " ";
        ans+=vals[i];
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
    return 0;
}