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
const int LOG = 30;

void solve(){
    
    ll n; cin >> n;
    ll k, l, r; cin >> k;
    map<ll, ll> mp;
    f(i,0,n){
        cin >> l >> r;
        if((r-l)+1>=k){
            mp[0]++;
            continue;
        } else if(l%k>r%k){
            mp[0]++; 
        } if((r+1)%k==0){}
        else    
        mp[(r+1)%k]--;
        mp[l%k]++;

    }

    ll tot = 0, mx = 0;
    for(auto data: mp){
        //cout << data.F << " " << data.S << "\n";
        tot+= data.S;
        mx = max(mx, tot);
    }

    cout << mx << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t= 1;
    //cin >> t;
    while(t--){
        solve(); 
    }
}

