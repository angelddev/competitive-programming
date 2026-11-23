#include<bits/stdc++.h>
 
#define ll long long 
#define all(a) begin(a), end(a)
#define pll pair<ll, ll> 
#define vll vector<ll>
#define vvl vector<vll>
#define vpl vector<pll> 
#define f(i, s, e) for(ll i=s; i<e; i++)
#define cf(i, s, e) for(ll i=s; i<=e; i++)
#define rf(i, s, e) for(ll i=s; i<e; i--)
#define MOD(x) ((((x)%mod) + mod)%mod)
#define F first
#define S second
#define pb push_back 
using namespace std; 
typedef long double ld;
 
const ll INF = 1e18; 
const ll mod = 1e9 + 7;
 
void solve(){
 
    ll n, q; cin >> n >> q;
    vll reactions(n);
    f(i,0,n) cin >> reactions[i];
 
    vll pfx(n);
    pfx[0]=reactions[0];
    f(i,1,n){
        pfx[i]=(pfx[i-1]+reactions[i])%mod;
    }

    vll pfxsqd(n);
    pfxsqd[0]=(reactions[0]*reactions[0])%mod;
    f(i,1,n){
        pfxsqd[i]=(pfxsqd[i-1]+(reactions[i]*reactions[i])%mod)%mod;
    }
 
    ll l, r, sum;
    f(i,0,q){
        cin >> l >> r;
        if(l!=1)
            cout << MOD(MOD(pfx[r-1]-pfx[l-2])*MOD(pfx[r-1]-pfx[l-2])-MOD(pfxsqd[r-1]-pfxsqd[l-2]))*500000004%mod << endl;
        else cout << MOD(MOD(pfx[r-1])*MOD(pfx[r-1])-MOD(pfxsqd[r-1]))*500000004%mod << endl;
    }
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
}