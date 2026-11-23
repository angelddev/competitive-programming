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

    ll n; cin >> n;
    vll nums(n+1);
    ll x;
    cf(i,1,n){
        cin >> x;
        nums[i]=abs(x);
    }

    if(n<=2){
        cout << "YES\n";
        return;
    }

    ll median=n/2;
    ll chosenone=nums[1];
    sort(all(nums));

    ll idx;
    cf(i,1,n){
        if(nums[i]==chosenone){
            idx=i;
            break;
        }
    }

    if(idx<=median+1){
        cout << "YES\n";
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