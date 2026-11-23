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

ll power(ll b, ll e) {
    ll res = 1;
    b %=MOD;
    while (e>0) {
        if (e%2== 1) res=(res*b)%MOD;
        b=(b*b)%MOD;
        e/=2;
    }
    return res;
}

void solve(){

    ll n;
    cin >> n;
    map<ll, ll> freqs;
    ll x;
    f(i,0,n){
        cin >> x;
        freqs[x]++;
    }

    map<ll, pll> dp;
    if(freqs.count(-1)){
        ll w = power(2, freqs[-1]-1);
        dp[0] = {w,0};
        dp[-1] = {0,w};
    }else{
        dp[0] = {1, 0};
    }

    for(auto p : freqs){
        ll val=p.F;
        ll c=p.S;
        if(val==-1) continue;
        ll w = power(2, c-1);
        map<ll, pll> nxt;

        for(auto d : dp){
            ll sum=d.F;
            ll ev=d.S.F;
            ll od=d.S.S;

            if(ev>0){
                nxt[sum].F = (nxt[sum].F+ev*w)%MOD;
                nxt[sum+val].S=(nxt[sum+val].S+ev*w)%MOD;
            }
            if(od>0){
                nxt[sum].S=(nxt[sum].S+od*w)%MOD;
                nxt[sum-val].F=(nxt[sum-val].F+od*w)%MOD;
            }
        }
        swap(dp, nxt);
    }

    ll ans=(dp[0].F+dp[0].S)%MOD;
    cout << ans << "\n";

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