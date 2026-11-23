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
    vll nums(n);

    if(n<=6){
        cout << ((ll)1<<(n-1)) << "\n";
        return;
    }

    f(i,1,7){
        nums[i-1]= ((ll)1<<(i-1));
    }

    f(i,6,n){
        ll sum=0;
        f(j,i-6, i){
            sum+=MOD(nums[j]);
        }
        nums[i]= MOD(sum);
    }

    cout << MOD(nums[n-1]) << "\n";
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}