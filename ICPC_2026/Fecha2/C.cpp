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
 
vll pfx;
ll prob = 1;

void fill(){
    pfx.assign(1e6+2, 0);
    pfx[3]=1;
    pfx[4]=2;

    ll flag = 0;
    ll cont = 2;
    f(i,5,1e6+1){
        if(flag==2){
            flag=0;
            cont++;
        }
        pfx[i]=(pfx[i-1]+cont)%MOD;
        flag++;
    }

}

tuple<ll, ll, ll> extendedGcd(ll a, ll b){
    if(b == 0){
        if(a > 0) return {a, 1, 0};
        else return {-a, -1, 0};
    }else{
        auto[d, x, y] = extendedGcd(b, a%b);
        return {d, y, x - y*(a/b)};
    }
}

ll modularInverse(ll a, ll m){        
    auto[d, x, y] = extendedGcd(a, m);
    if(d != 1) return -1; 
    if(x<0) x+=m;
    return x;
}

ll ncr(ll n, ll r){
    if(r<0 || r>n) return 0;
    r=min(r, n-r);
    ll ans=1;
    for(ll den=1, num=n; den<= r; den++, num--){
        ans=ans*num; ans=ans%MOD;
        ans=ans*modularInverse(den, MOD); ans=ans%MOD;
    }
    return ans;
}

void solve(){
    
    ll n; cin >> n;

    ll ans = (((pfx[n]*modularInverse(ncr(n, 3), MOD))%MOD)*prob)%MOD;
    prob = ans;
    cout << ans << "\n";    

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t; cin >> t;

    fill();
    while(t--){
        solve(); 
    }
}