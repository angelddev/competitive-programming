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


    ll s, c;
    map<ll, ll> vec;
    f(i,0,n){
        cin >> s >> c;
        vec[s]+=c;
    }

    for(auto v : vec){
        
        if(v.S>1){
            vec[v.F*2]+=(v.S)/2;
            if(v.S%2) vec[v.F] = 1;
            else vec[v.F] = 0;
        } else continue;
        cout << v.F << " " << v.S << "\n";
    }
 
    ll ans = 0;
    for(auto v : vec){
        if(v.S>0){
            ans++;
            //cout << v.F << " ";
        }
    }
    //cout << "\n";
    cout << ans << "\n";
    


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; //cin >> t;
    while(t--){
        solve(); 
    }
}

