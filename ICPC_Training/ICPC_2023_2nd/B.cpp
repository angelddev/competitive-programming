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
   
    ll n, q; cin >> n >> q;

    map<ll,ll>freqs;
    ll x;
    vll original(n);
    f(i,0,n){
        cin >> x; 
        original[i]=x;
        freqs[x]++;
    }

    vpl queries(q);
    f(i,0,q){
        cin >> queries[i].first;
        cin >> queries[i].second;
    }

    vll fa(n+1);
    fa[0]=1;
    cf(i,1,n){
        fa[i]=(fa[i-1]*i)%mod;
    }

    vll ans;
    ll num=1;
    for(auto it=freqs.begin(); it!=freqs.end(); ++it){
        num=((num%mod)*fa[it->second])%mod;
    }

    ll n1=num*(modularInverse(fa[n], mod))%mod;
    ans.pb(n1);

    f(i,0,q){
        ll subs=freqs[original[queries[i].first-1]]--;
        freqs[queries[i].second]++;
        original[queries[i].first-1]=queries[i].second;

        num=(num%mod*freqs[queries[i].second]%mod)%mod;
        num=num%mod*modularInverse(subs, mod)%mod;

        ll n1=num%mod*(modularInverse(fa[n], mod))%mod;
        ans.pb(n1);
    }   

    for(ll x : ans){
        cout << x << "\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    //ll t; cin >> t;
    //while(t--)
        solve();
}