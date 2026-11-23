#include <bits/stdc++.h>

#define ll long long 
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
const int LOG = 30;


void solve(){
 
    ll n, k; cin >> n >> k;

    vll arr(n+1);
    f(i,0,n){
        cin >> arr[i];
    }

    vll vis(n+1);

    ll l = 0, r = 0, cur = 0, amount = 0, ans = 0;
    while(r!=n&&l<=r){
        
        if(!vis[r]){
            vis[r]=1;
            cur+=arr[r];
            amount++;
        }
        if(cur>k){
            while(l<r&&cur>k){
                cur-=arr[l];
                l++;
                amount--;
            }

            if(l==r&&cur>k){
                amount = 0;
                cur = 0;
                l++;
            }
        }
        r++;
        ans = max(amount, ans);
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; //cin >> t;
    while(t--){
        solve(); 
    }
}

