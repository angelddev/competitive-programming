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
    
    vll arr(n);
    f(i,0,n){
        cin >> arr[i];
    }

    ll need = 0, mx = INF;
    f(i,1,n){
        if(arr[i]<arr[i-1]){
            need=max(need, arr[i-1]-arr[i]);
        }
        if(i!=n-1){
            mx = min(mx, (arr[i+1]-arr[i])-(arr[i]-arr[i-1]));
        }
    }

    if(need > 0 && (mx < 0 || need > mx)) cout << "NO\n";
    else cout << "YES\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t; cin >> t; 
    while(t--){
        solve(); 
    }
}