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
    ll n; cin >> n;


    char t;
    ll prod = 1, x, op=1;
    f(i,0,n){
        cin >> t;
        cin >> x;
        if(t=='?'){
            ll sm = ((op+((prod)*(x-1))%MOD)%MOD)%MOD;
            cout << sm << "\n";
        }
        else {
            if(t=='*'){
                prod=(prod*x)%MOD;
                op=(op*x)%MOD;
            }
            else op=(op+x)%MOD;
        } 
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t=1;
    while(t--){
        solve(); 
    }
}