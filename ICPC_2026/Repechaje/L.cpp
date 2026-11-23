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

    string s;
    map<string, ll> freq;
    f(i,0,n){
        cin >> s;
        string temp="";
        f(i,0,s.size()){
            temp+=s[i];
            freq[temp]++;
        }
    }

    ll mx = 0;
    for(auto u : freq){
        if(u.S>1){
            if(u.F.size()>mx){
                mx = u.F.size();
            }
        }
    }

    cout << mx << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; //cin >> t;
    while(t--){
        solve(); 
    }
}

