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
 
    ll n, m, k; cin >> n >> m >> k;

    vll missing(m+1);
    f(i,0,m){
        cin >> missing[i];
    }

    ll x;
    vll know(n+1);
    f(i,0,k){
        cin >> x;
        know[x]=1;
    }

    if(k==n){
        f(i,0,m){
            cout << "1";
        }
        cout << "\n";
        return;
    }
    if(k<n-1){
        f(i,0,m){
            cout << "0";
        }
        cout << "\n";
        return;
    }


    cf(i,1,n){
        if(know[i]==0){
            x = i;
            break;
        }
    }

    
    f(i,0,m){
        if(missing[i]==x){
            cout << "1";
        } else cout << "0";
    } cout << "\n";


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; cin >> t;
    while(t--){
        solve(); 
    }
}

