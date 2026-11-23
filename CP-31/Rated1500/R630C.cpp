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

    ll n, k; cin >> n >> k;
    string s; cin >> s;
    ll ans=0;
    ll mx=0;
    f(i,0,k/2){
        map<char, ll> bucket;
        mx=0;
        for(ll j=i; j<s.size(); j+=k){
            bucket[s[j]]++;
            mx=max(bucket[s[j]], mx);
        }
        for(ll j=k-1-i; j<s.size(); j+=k){
            bucket[s[j]]++;
            mx=max(bucket[s[j]], mx);
        }
        ans+=2*(n/k)-mx;
    }
    map<char, ll> bucket;
    mx=0;
    if(k%2==1){
        for(ll j=k/2; j<s.size(); j+=k){
            bucket[s[j]]++;
            mx=max(bucket[s[j]], mx);
        }
        ans+=(n/k)-mx;
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t; cin >> t; 
    while(t--){
        solve(); 
    }
}