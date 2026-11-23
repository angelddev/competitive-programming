#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define vll vector<ll>
#define vpl vector<pll>
#define vvll vector<vll>
#define f(i,s,e) for(ll i=s; i<e; i++)
#define cf(i,s,e) for(ll i=s; i<=e; i++)
#define rf(i,s,e) for(ll i=s; i>=e; i--)
#define all(a) begin(a), end(a)
#define pb push_back
#define F first
#define S second
#define endl '\n'
using namespace std; 

const ll MOD = 1e9+7, INF = 1e18;

ll n, m, k; 

void solve(){
    
    ll n; cin >> n;

    vll blue(n), red(n);
    f(i,0,n){
        cin >> blue[i];
    }
    f(i,0,n){
        cin >> red[i];
    }

    sort(all(blue));
    sort(all(red));
    reverse(all(red));

    ll mx = 0, mn = INF;
    f(i,0,n){
        ll temp = blue.back()+red.back();
        //cout << blue.back() << " " << red.back() << "\n";
        blue.pop_back(), red.pop_back();
        mx = max(temp, mx);
        mn = min(temp, mn);
    }

    cout << mx-mn << "\n";
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