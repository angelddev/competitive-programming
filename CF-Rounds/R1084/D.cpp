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
 
ll gmin(vll& v) {
    ll n=v.size();
    if (n==0) return 0;
    ll i=0, j=1, p=0;
    while (i<n && j<n && p<n) {
        ll a_val=v[(i+p)%n], b_val=v[(j+p)%n];
        if (a_val==b_val) p++;
        else {
            if (a_val>b_val) i=i+p+1;
            else j=j+p+1;
            if (i==j) j++;
            p=0;
        }
    }
    return min(i, j);
}

void solve(){
    ll n, x, y; cin >> n >> x >> y;
    vll numsoutside, numsinside;
    ll p; 
    f(i,0,n){
        cin >> p;
        if(i < x || i >= y) numsoutside.pb(p);
        else numsinside.pb(p);
    }

    ll s_in = gmin(numsinside);

    if(numsoutside.size()==0){
        f(k, 0, numsinside.size()) 
            cout << numsinside[(s_in+k)%numsinside.size()] << " ";
        cout << "\n";
        return;
    }
        
    ll j;
    for(j=0; j<numsoutside.size(); j++){
        if(numsoutside[j] > numsinside[s_in]){
            break;
        }
    }

    f(i, 0, numsoutside.size()) {
        if(i == j){
            f(k, 0, numsinside.size()) 
                cout << numsinside[(s_in+k)%numsinside.size()] << " ";
        }
        cout << numsoutside[i] << " ";
    }
    
    if(j == numsoutside.size()){
        f(k, 0, numsinside.size()) 
            cout << numsinside[(s_in+k)%numsinside.size()] << " ";
    }
    
    cout << "\n";
}

int main(){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t; cin >> t;
    while(t--) solve();
}