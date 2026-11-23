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

void solve(){
   
    ll n, q; cin >> n >> q;
    vll nums(n);
    f(i,0,n){
        cin >> nums[i];
    }

    ll lgsize = 31 - __builtin_clz(n);
    lgsize++;
    vvl sparse(lgsize, vll(n, INF));
    f(i,0,n){
        sparse[0][i]=nums[i];
    }

    f(i,1,lgsize){
        for(ll j=0; j+(1<<i)<=n; j++){
            sparse[i][j]=min(sparse[i-1][j], sparse[i-1][j+(1<<(i-1))]);
        }
    }


    ll l, r;
    f(i,0,q){
        cin >> l >> r;
        ll k = floor(log2(r-l+1));
        cout << min(sparse[k][l-1], sparse[k][r-(1<<k)]) << "\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    //ll t; cin >> t;
    //while(t--)
        solve();
}