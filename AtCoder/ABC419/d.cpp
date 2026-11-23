#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define vll vector<ll>
#define vpl vector<pll>
#define vvll vector<vll>
#define f(i, s, e) for(ll i=s; i<e; i++)
#define cf(i, s, e) for(ll i=s; i<=e; i++)
#define rf(i, s, e) for(ll i=s; i>=e; i--)
#define all(a) begin(a), end(a)
#define endl '\n'
#define pb push_back 
#define F first 
#define S second 
using namespace std; 

const ll INF = 1e18; 
const ll MOD = 1e9+7; 

ll n, m, k; 

void solve(){

    ll n, m; cin >> n >> m;

    string s, t; cin >> s >> t;

    ll x, y;
    vll arr(n+7, 0);
    f(i,0,m){
        cin >> x >> y;
        arr[x-1]++;
        arr[y]--;
    }
    f(i,1,n){
        arr[i]= arr[i]+arr[i-1];
    }

    f(i,0,n){
        if(arr[i]%2){
            cout << t[i];
        } else cout << s[i];
    } cout << "\n";

}

int main(){
    #ifdef DEBUG
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout); 
    #else 
        ios_base::sync_with_stdio(0); 
        cin.tie(NULL); 
    #endif 

    ll t=1;
    // cin>>t; 
    while(t--){
        solve(); 
    }
}