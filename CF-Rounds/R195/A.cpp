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
 
    ll a, b;
    cin >> a >> b;

    if(b>=a){
        cout << "-1\n";
        return;
    }
    if(b*2<=a){
        cout << b << "\n";
        return;
    }

    ll act = 1;
    while(act<a){
        act++;
        ll ones = b;
        ll temp = 0;
        while(true){
            if(ones>=act){
                ones-=act;
                temp++;
            } else break;
            if(ones*2+(temp*(act+1))<=a){
                cout << temp+ones << "\n";
                return;
            }
        }
    }

    cout << "-1\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; cin >> t;
    while(t--){
        solve(); 
    }
}

