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
    
    ll n; cin >> n;
    ll cpy=n;
    vll ans(3, 0);
    f(i,2,sqrt(cpy)){
        if(n%i==0){
            n/=i;
            ans[0]=i;
            break;
        }
    }
    f(i,2,sqrt(cpy)){
        if(n%i==0&&i!=ans[0]){
            n/=i;
            ans[1]=i;
            break;
        }
    }
    if(ans[0]!=0&&ans[1]!=0&&n!=ans[0]&&ans[1]!=n){
        cout << "YES\n";
        cout << ans[0] << " " << ans[1] << " " << n << "\n";
    }
    else cout << "NO\n";
}





int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    ll t; cin >> t;
    while(t--)
    solve();
}