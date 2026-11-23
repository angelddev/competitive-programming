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

void solve(){
    
    ll n; cin >> n;
    vll nums(n);

    ll sum=0;
    f(i,0,n){
        cin >> nums[i];
        sum+=nums[i];
    }

    ll mn=INF;
    for(ll mask=1; mask<(1<<n); mask++){
        ll temp=0;
        f(i,1,n){
            if(mask&(1<<i))
            temp+=nums[i];
        }
        ll diff=abs((sum-temp)-temp);
        mn=min(diff, mn);
    }

    cout << mn << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    //ll t; 
    //cin >> t;
    //while(t--)
        solve();
        
    return 0;
}