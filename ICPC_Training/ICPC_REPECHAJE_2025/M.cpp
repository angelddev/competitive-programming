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

const ll INF = 1e9+10;
const ll MOD = 1e9 +7;


void solve(){

    ll n, k; cin >> n >> k;

    vll wall;
    ll x;
    ll mx=INF;
    f(i,0,n){
        cin >> x;
        wall.pb(x);
        mx=min(mx, wall[i]);
    }

    ll l=0, r=INF;
    while(l<=r){
        ll mid=(l+r)/2;
        ll rmin=INF;

        //cout << mid << "\n";
        f(i,0,n){
            ll nr;
            if(wall[i]<mid){
                nr=k-(mid-wall[i]);
                rmin=min(i+nr, rmin);
                if(rmin<i){
                    rmin=-1;
                    break;
                }
            }
            
        }

        if(rmin==-1){
            r=mid-1;
        } else{
            l=mid+1;
            mx=mid;
        } 
    }

    cout << mx << "\n";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t=1; 
    while(t--){
        solve(); 
    }
}