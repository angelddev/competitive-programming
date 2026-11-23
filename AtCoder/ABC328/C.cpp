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

    map<char, ll> last;

    char c = s[0];
    ll it = 1, cont = 1;
    ll ans = 0;

    while(it < s.size()){
        if(s[it]==c) cont++;
        else {
            if(last[c]<cont){
                ans+=cont-last[c];
                last[c]=cont;
            }
            cont = 1;
            c = s[it];
        }
        it++;
    }

    if(last[c]<cont){
        ans+=cont-last[c];
        last[c]=cont;
    }

    cout << ans << "\n";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; //cin >> t;
    while(t--){
        solve(); 
    }
}

