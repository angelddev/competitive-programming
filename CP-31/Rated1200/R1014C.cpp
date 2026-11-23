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


void solve(){

    ll n; cin >> n;
    vll nums(n);
    f(i,0,n){
        cin >> nums[i];
    }

    ll sum=0, mx=0;
    vll odd, even;
    f(i,0,n){
        if(nums[i]%2==1) odd.pb(nums[i]);
        else even.pb(nums[i]);
        sum+=nums[i];
        mx=max(nums[i], mx);
    }

    if(even.size()==0||odd.size()==0) {
        cout <<  mx << "\n";
        return;
    }
    cout << sum-odd.size()+1 << "\n";



}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t; cin >> t; 
    while(t--){
        solve(); 
    }
}