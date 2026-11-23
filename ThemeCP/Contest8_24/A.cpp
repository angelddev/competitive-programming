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
    string s; cin >> s;

    if(count(all(s), '_') == n){
        cout << n/2 << "\n";
        return;
    }

    stack<ll> stk;
    ll ans = 0;
    f(i,0,n){
        if(s[i]=='('){
            stk.push(i);
        } else if (s[i]=='_'){
            if(stk.empty()){
                stk.push(i);
            } else {
                ans+=i-stk.top();
                stk.pop();
            }
        } else {
            ans+=i-stk.top();
            stk.pop();
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

