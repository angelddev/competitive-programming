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

    ll n; 
    cin >> n; 

    vll nums(n);

    f(i,0,n){
        cin >> nums[i];
    }

    ll flips=0;
    vll idx;
    for(ll i=n-1; i>=0; i--){
        if(flips%2){
            nums[i]=nums[i]*-1;
        }
        if(nums[i]>0){
            flips++;
            idx.pb(i+1);
        }
    }

    cout << idx.size() << "\n";
    f(i,0,idx.size()){
        cout << idx[i] << " ";
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t; cin >> t; 
    while(t--){
        solve(); 
    }
}