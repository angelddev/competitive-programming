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

    ll n; cin >> n;

    map<ll, ll> info;
    vll arr(n+1);
    cf(i,1,n){
        cin >> arr[i];
    }

    ll ans = 0;
    vpl options;
    cf(i,1,n){
        if(i+(arr[i]-1)>=n)
        options.pb({i+(arr[i]-1), i-1});
    }

    sort(all(options));
    reverse(all(options));

    for(pll el : options){
        ll pnt = el.F+el.S;
        if(info[pnt] == 0){
            info[el.F] = max(info[el.F], pnt);
        } else {
            info[el.F] = max(info[el.F], info[pnt]);
        }
    }

    cout << max(info[n], n) << "\n";

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
    cin>>t; 
    while(t--){
        solve(); 
    }
}