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
 
ll t, n, m, k, a, b, tot; 

void solve(){
    
    ll n, health, reload; cin >> n >> health >> reload;
    vll dmg(n);
    f(i,0,n){
        cin >> dmg[i];
    }
    vll pfx(n);
    pfx[0]= dmg[0];
    f(i,1,n) pfx[i]=pfx[i-1]+dmg[i];

    ll sum=pfx[n-1];
    ll ans=0;

    ll rounds=(health-1)/sum;  
    if (rounds > 0) {
        ans = rounds*(reload+n);
        health-=rounds*sum;
    }

    if(health<=0){
        cout << ans << "\n";
        return;
    }

    auto it=lower_bound(pfx.begin(), pfx.end(), health);
    if(it==pfx.begin()){
        cout << ans+1 << "\n";
        return;
    }
    ll dyingpoint=it-pfx.begin();

    ll mx=dmg[dyingpoint];
    f(i,dyingpoint,n){
        mx=max(dmg[i], mx);
    }
    ll weakest=dmg[0];
    

    ll newdyingpoint=dyingpoint;
    cf(i,0,dyingpoint){
        if (pfx[i]>=health) {
            cout << ans+(i+1)<<"\n";
            return;
        }
        weakest=min(dmg[i], weakest);
        if(pfx[i]-weakest+mx>=health){
            cout << ans+(i+1) << "\n";
            return;
        }
    }
    cout << ans+(dyingpoint+1) << "\n";

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    ll t; cin >> t;
    while(t--)
    solve();
}