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




ll check(ll sz, ll x, ll y, ll days){

    ll ans=(2ll*days*days-2ll*days+1);

    days--;
    ll leftFlag = 0, rightFlag = 0, upFlag = 0, downFlag = 0, ldFlag = 0, luFlag = 0, ruFlag = 0, rdFlag = 0;
    if(x+days>sz){
        downFlag = ((x+days)-sz)*((x+days)-sz);
    }
    if(x-days<1){
        upFlag = ((x-days)-1)*((x-days)-1);
    }
    if(y+days>sz){
        rightFlag = ((y+days)-sz)*((y+days)-sz);
    }
    if(y-days<1){
        leftFlag = ((y-days)-1)*((y-days)-1);
    }

    ll R = days;

    if(downFlag>0&&leftFlag>0){
        ll n = R - ((sz - x) + (y - 1));
        if (n > 0) ldFlag = (n*(n-1))/2;
    }
    if(downFlag>0&&rightFlag>0){
        ll n = R - ((sz - x) + (sz - y));
        if (n > 0) rdFlag = (n*(n-1))/2;
    }
    if(upFlag>0&&rightFlag>0){
        ll n = R - ((x - 1) + (sz - y));
        if (n > 0) ruFlag = (n*(n-1))/2;
    }
    if(upFlag>0&&leftFlag>0){
        ll n = R - ((x - 1) + (y - 1));
        if (n > 0) luFlag = (n*(n-1))/2;
    }

    ans+=(-rightFlag-leftFlag-upFlag-downFlag+ldFlag+luFlag+rdFlag+ruFlag);
    
    return ans;
}

void solve(){
    

    ll n, k, x, y, d;
    cin >> n >> k >> x >> y;

    ll l = 1, r = 2e8;
    ll ans = 0;
    while(l<=r){
        
        ll mid = (l+r)/2;
        ll covered = check(n, x, y, mid);

        if(covered>=k){
            ans = mid;
            r=mid-1;    
        } else l = mid+1;

    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t=1;
    while(t--){
        solve(); 
    }
}