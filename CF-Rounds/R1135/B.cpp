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
    ll cont1 = 0, cont0 = 0;
    string s; cin >> s;
    f(i,0,n){
        if(s[i]=='1'){
            cont1++;
        } else cont0++;
    }

    if(cont1>=cont0){
        cont1 = min(n, cont1+k);
        cont0 = n-cont1;
    } else{
        cont0 = min(n, cont0+k);
        cont1 = n-cont0;
    }


    ll ans = 1;
    cf(i,1,max(cont0, cont1)){
        ans+=i;
    }
    cf(i,1,min(cont0, cont1)){
        ans+=i;
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

