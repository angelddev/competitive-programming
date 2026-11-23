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

const ll INF = 1e9;
const ll MOD = 1e9 +7;

ll t, n, m, k, a, b, c; 
ll dp[25][105][105][105]; 

tuple<ll, ll, ll> extendedGcd(ll a, ll b){
    if(b==0){
        if(a>0) return {a, 1, 0}; 
        else return {-a, -1, 0}; 
    }else{
        auto[d, x, y] = extendedGcd(b, a%b);
        return {d, y, x-y*(a/b)};
    }
}

ll modularInverse(ll a, ll m){
    auto[d, x, y] = extendedGcd(a, m); 
    if(d!=1) return -1; 
    if(x<0) x+=m;
    return x;
}

ll ncr(ll n, ll r){
    r=min(r, n-r);
    ll ans=1;
    for(ll den=1, num=n; den<=r; den++, num--){
        ans*=num; ans=ans%MOD;
        ans=ans*modularInverse(den, MOD); ans=ans%MOD;
    }
    return ans; 
}

ll ans(ll n, ll r, ll g, ll b){
    if(dp[n][r][g][b] != -1) return dp[n][r][g][b]; 
    if(n==1){
        ll cnt=0;
        if(r>0) cnt++;
        if(g>0) cnt++;
        if(b>0) cnt++;
        return cnt; 
    } 
    ll res=0;
    if(r>=n) res= (res + ans(n-1, r-n, g, b))%MOD; 
    if(g>=n) res= (res + ans(n-1, r, g-n, b))%MOD; 
    if(b>=n) res= (res + ans(n-1, r, g, b-n))%MOD; 
    if(n%2 ==0 && r>=n/2 && g>=n/2) res = (res + ncr(n, n/2)*ans(n-1, r-n/2, g-n/2, b)) %MOD; 
    if(n%2 ==0 && r>=n/2 && b>=n/2) res = (res + ncr(n, n/2)*ans(n-1, r-n/2, g, b-n/2)) %MOD; 
    if(n%2 ==0 && g>=n/2 && b>=n/2) res = (res + ncr(n, n/2)*ans(n-1, r, g-n/2, b-n/2)) %MOD; 
    if(n%3 ==0 && r>=n/3 && g>=n/3 && b>=n/3) res = (res + (ncr(n-n/3, n/3)*(ncr(n, n/3)*ans(n-1, r-n/3, g-n/3, b-n/3)))%MOD) %MOD; 
    dp[n][r][g][b]=res; 
    return res; 
}

void solve(){
    cin>>n>>a>>b>>c;
    cout<<ans(n, a, b, c)<<"\n"; 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    memset(dp, -1, sizeof(dp)); 
    t=1; 
    while(t--){
        solve(); 
    }
}