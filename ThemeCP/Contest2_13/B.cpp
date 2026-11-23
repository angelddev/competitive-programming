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
 

    ll n; cin >> n;
    vll arr(n+1);
    f(i,0,n){
        cin >> arr[i];
    }

    ll l = 1, r = n-2;
    vll vis(n+1);
    while(l<=r){
        vis[l]=1;

        if(arr[l-1]>0){
            ll rest = arr[l-1];
            arr[l-1]=0;
            arr[l]-=2*rest;
            arr[l+1]-=rest;
        }
        if(!vis[r]){
            vis[r]=1;
            if(arr[r+1]>0){
                ll rest = arr[r+1];
            arr[r+1]=0;
            arr[r]-=2*rest;
            arr[r-1]-=rest;
            }
        }

        l++, r--;
    }   

    f(i,0,n){
        if(arr[i]!=0){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; cin >> t;
    while(t--){
        solve(); 
    }
}

