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
    vll arr(n);
    deque<ll> ans;
    f(i,0,n) cin >> arr[i];

    vll cp=arr;
        sort(cp.begin(), cp.end());
        if(cp==arr){
            cout << 0 << "\n";
            return;
        }

    if(arr[n-2]>arr[n-1]){
        cout << -1 << "\n";
        return;
    }

    if(arr[n-1]<0){
        vll cp=arr;
        sort(cp.begin(), cp.end());
        if(cp!=arr){
            cout << -1 << "\n";
            return;
        }
    }
    

    for(ll i=n-3; i>=0; i--){
            arr[i]=arr[n-2]-arr[n-1];
            ans.push_front(n); ans.push_front(n-1); ans.push_front(i+1);
    }

    cout << ans.size()/3;
    f(i,0,ans.size()){
        if(i%3==0)
        cout << "\n";
        cout << ans[i] << " ";
    }
    cout << "\n";

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    ll t; cin >> t;
    while(t--)
    solve();
}