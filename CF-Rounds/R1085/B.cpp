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
const ll mod = 998244353;
 
ll t, n, m, k, a, b, tot; 
 
void solve(){
   
    ll flashes, tronics, time;
    cin >> flashes >> tronics >> time;

    vll flashtimes(flashes);
    f(i,0,flashes) cin >> flashtimes[i];


    ll reseted=0, mx=0;
    f(i,0,flashes){
        if(reseted==tronics){
            reseted=0; mx=(flashtimes[i]-flashtimes[i-tronics])/(tronics);
        }
        else if(i==0){
            mx+=flashtimes[i]/(tronics-reseted);
            reseted++;
        }
        else {
            mx+=(flashtimes[i]-flashtimes[i-1])/(tronics-reseted);
            reseted++;
        }
    }   

    if(reseted==tronics){
        reseted=0; mx=flashtimes[flashes-1]-flashtimes[flashes-tronics];
    }
    mx+=(time-flashtimes[flashes-1]);

    cout << mx << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    ll t; cin >> t;
    while(t--)
        solve();
}