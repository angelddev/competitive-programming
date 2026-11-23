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
const ll mod = 1e9 + 7;
 
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
    vll nums(n);
    f(i,0,n) cin >> nums[i];
    
    map<ll, ll> diffs;
    f(i,0,n) diffs[nums[i]-i]++;

    ll sum=0;
    for(auto it=diffs.begin(); it!=diffs.end(); ++it){
        if(it->second>1){
            ll k= it->second;
            sum+=(k*(k-1))/2;
        }
    }

    cout << sum << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    ll t; cin >> t;
    while(t--)
        solve();
}