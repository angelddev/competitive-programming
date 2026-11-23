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

    ll n, k; cin >> n >> k;

    string s ; cin >> s;
    f(i,0,n-k){
        if(s[i]=='1'){
            s[i]='0';
            if(s[i+k]=='0') s[i+k]='1';
            else s[i+k]='0';
        }
    }

    f(i,0,n){
        if(s[i]=='1') {
            cout << "NO\n"; return;
        }
    }

    cout << "YES\n";
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t; cin >> t;
    while(t--){
        solve(); 
    }
}