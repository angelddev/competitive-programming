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

tuple<ll, ll, ll> extendedGcd(ll a, ll b){
    if(b==0){
        if(a>0) return {a, 1, 0};
        else return {-1, -1, 0};
    } else{
        auto[d, x, y]=extendedGcd(b, a%b);
        return {d, y, x-y*(a/b)};
    }
}

ll modularInverse(ll a, ll m){
    auto[d, x, y] = extendedGcd(a, m);
    if(d!=1) return -1;
    if(x<0) x+=m;
    return x;
}



void solve(){

    ll n, q; cin >> n >> q;

    vll ans(n+1);

    vll lastUp(n+1);
    vll Current(n+1);
    Current[1]=1;
    ll inv2=modularInverse(2, MOD);
    ll G=1;
    ll invG=1;
    ll x;
    ll global=0;

    f(i,0,q){
        cin >> x;

        ll newProb = (((G*x)%MOD)*inv2)%MOD;
        global=(global+newProb)%MOD;


        ll earn=(Current[x]*((global - lastUp[x] + MOD) % MOD))%MOD;
        ans[x]=(ans[x]+earn)%MOD;

        lastUp[x]=global;

        G=(G*inv2)%MOD;
        invG=(invG*2)%MOD;

        Current[x]=(Current[x]+(inv2*invG)%MOD)%MOD;
    }

    cf(i,1,n){
        ll earn=(Current[i]*((global - lastUp[i] + MOD) % MOD))%MOD;
        ans[i]=(ans[i]+earn)%MOD;

    }

    cf(i,1,n){
        cout << ans[i] << "\n";
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