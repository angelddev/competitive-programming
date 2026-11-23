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
 
const ll INF = 1e18+1; 
const ll mod = 1e9 + 7;
 
ll t, n, m, k, a, b, tot; 

void solve(){
    
    ll n, x; cin >> n >> x;

    vll nums(n);
    f(i,0,n) cin >> nums[i];
    vll pfx(n);
    pfx[0]=nums[0];
    map<ll, ll> mappy;
    ll ans=0;
    mappy[0]=1;
    f(i,1,n) {
        pfx[i]=pfx[i-1]+nums[i]; 
    }

    f(i,0,n){
        ans+=mappy[pfx[i]-x];
        mappy[pfx[i]]++;
    }

    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    //ll t; cin >> t;
    //while(t--)
    solve();
}