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

    sort(all(nums));
    reverse(all(nums));

    ll band=1;
    ll md=(nums[0]%nums[1]);
    f(i,2,n){
        if(nums[i]!=md){
            band=0;
            break;
        }

        md=nums[i-1]%nums[i];
    }

    if(band) cout << nums[0] << " " << nums[1] << "\n";
    else cout << "-1\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t; cin >> t;
    while(t--){
        solve(); 
    }
}