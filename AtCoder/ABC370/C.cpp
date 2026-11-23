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
 
    string s, t; cin >> s >> t;

    ll cont = 1;
    vector<string> ans;
    ll n = s.size();
    while(s!=t){
        cont++;
        ll flag = 0;
        f(i,0,n){
            if(s[i]>t[i]){
                flag = 1;
                s[i] = t[i];
                break;
            }
        }

        if(flag==0){
            rf(i,n-1,0){
                if(s[i]!=t[i]){
                    s[i] = t[i];
                    break;
                }
            }
        }

        ans.pb(s);
    }

    cout << cont-1 << "\n";
    for(string e : ans){
        cout << e << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; //cin >> t;
    while(t--){
        solve(); 
    }
}

