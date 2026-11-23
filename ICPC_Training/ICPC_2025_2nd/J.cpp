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
 

tuple<ll, ll, ll> extendedGcd(ll a, ll b){
    if (b==0){
        if(a>0) return{a,1,0};
        else return {-a,-1,0};
    }else{
        auto[d, x, y] = extendedGcd(b,a%b);
        return {d,y,x-y*(a/b)};
    }
}

ll  modularInverse(ll a, ll m){
    auto[d,x,y] = extendedGcd(a,m);
    if(d!=1)return -1;
    if(x<0) x+=m;
    return x;
}

void solve(){
   
    ll n; cin >> n;
    vpl queries(n);
    f(i,0,n){
        cin >> queries[i].first;
        cin >> queries[i].second;
    }   

    vll fa(10e6);
    fa[0]=1;
    f(i,1,10e6) fa[i]=(fa[i-1]%mod*i%mod)%mod;

    vll nums;
    for(pll query : queries){
        ll p=query.first, q=query.second;
        ll den = (fa[q+1]%mod*fa[(p+1)-(q+1)]%mod)%mod;
        ll ans=(fa[p+1]%mod*modularInverse(den,mod)%mod)%mod;
        nums.pb(ans);
    }

    for(ll x:nums) cout<< x << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    //ll t; cin >> t;
    //while(t--)
        solve();
}