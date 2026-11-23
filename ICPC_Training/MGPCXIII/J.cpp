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
unordered_map<ll, ll> apps;

ll cribb(ll x, ll mx){
    ll res = x;
    vll is_prime(2e6, 1);
    for (int p = 2; p< 2e6; p++) {
        ll temp=0;
        if (is_prime[p]) {
            for (int i = p; i < 2e6; i += p) {
                is_prime[i] = false;
                temp+=apps[i];
            }
        }
        if(mx<temp){
            res = p;
            mx=temp;
        }
    }

    return res;
}

void solve(){
    
    ll n; cin >> n;
    ll x, bst, freq=0;
    f(i,0,n){
        cin >> x;
        apps[x]++;
        if(freq<apps[x]){
            freq=apps[x];
            bst=x;
        }
    }
    ll mx = cribb(bst, freq);
    
    cout << mx << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t=1;
    while(t--){
        solve(); 
    }
}