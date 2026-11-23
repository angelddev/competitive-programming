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
 
    string s;
    cin >> s;

    ll ans = 1;
    ll flag=0, flag1=0;
    f(i,1,s.size()-1){
        if(s[i-1]==s[i+1]&&s[i]!=s[i-1]&&flag==0){
            ans++;
            flag=1;
        }
        if(s[i-1]==s[i+1]&&s[i]==s[i-1]&&flag1==0){
            ans++;
            flag1=1;
        }
    }

    cout << ans << "\n";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; cin >> t;
    while(t--){
        solve(); 
    }
}

