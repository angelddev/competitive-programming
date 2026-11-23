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
    ll n, t; cin >> n >> t;

    vll a(n);
    f(i,0,n) cin >> a[i];

    ll r=INF, l=0, ans;
    while(l<=r){

        ll mid=(r+l)/2;
        ll sum=0;
        f(i,0,n){
            sum+=mid/a[i];
            if(sum>=t)
                break;
        }
        if(sum>=t){
            ans=mid;
            r=mid-1;
        } else {
            l=mid+1;
        }
    }
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
}