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
const ll mod = 1e9 + 7;
 
ll t, n, m, k, a, b, tot; 
 
void solve(){
   
    ll n; cin >> n;
    vll arr(n);
    f(i,0,n) cin >> arr[i];

    if(n==1){
        cout << 0 << "\n";
        return;
    }

    if(n==2){
        if(arr[1]==arr[0]||max(arr[0], arr[1])==7-min(arr[0], arr[1]))
            cout << 1 << "\n";
        else cout << 0 << "\n";
        return;
    }
        
    ll sum=0;
    for(ll i=1; i<n; i++){
        if(arr[i]==arr[i-1]||max(arr[i], arr[i-1])==7-min(arr[i], arr[i-1])){
            sum++;
            if(i<n-1){
                if(arr[i+1]!=5&&arr[i+1]!=2){
                arr[i]=5;
            } else arr[i]=1;
            }
        }
    }
    cout << sum << "\n";

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    ll t; cin >> t;
    while(t--)
        solve();
}