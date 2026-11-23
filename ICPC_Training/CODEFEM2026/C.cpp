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
 
    ll n, z; cin >> n >> z;

    ll x, y, w;

    ll mx = 0, mxDays = 0, mxPen = 0, secmx = 0;

    f(i,0,n){
        cin >> x >> y >> w;

        if(x>mx){
            secmx = mx;
            mx = x;
            mxDays = y;
            mxPen = x-w;
        }    else
        if(x==mx){
            secmx = mx;
            mxDays = max(mxDays, y);
            mxPen = max(mxPen, x-w);
        }
    }

    if(mx==secmx){
        cout << mx*z << "\n";
        return;
    }
    if(mxPen>secmx){
        ll cont = 1, d = 1;
        ll sum = 0;
        while(cont<=z){
            if(d>mxDays){
                d = 1;
                sum+=mxPen;
            } else sum+=mx;
            cont++;
        }
    }




}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1;// cin >> t;
    while(t--){
        solve(); 
    }
}

