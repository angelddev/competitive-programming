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

const ll INF = 1e18;
const ll MOD = 1e9 +7;
const int LOG = 30;

void solve(){

    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    
    ll hrs = 0;

    ll cp = a;
    
    while(a>0){
        a-=b;
        a-=c;
        hrs++;
    }

    ll trns=0;
    while(cp>0){
        cp-=b;
        if(trns>=d){
            cp-=(10*c);
        }
        trns++;
    }

    cout << min(trns, hrs) << "\n";
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t; cin >> t;
    while(t--){
        solve(); 
    }
}