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

    string pos;
    cin >> pos;

    ll i=0, p=0;
    f(j,0,2*n-1){
        if(pos[j]=='1'){
            if(pos[j+1]=='1'){
                if(j%2){ 
                    i++;
                }
                else p++;
            }
            else{
                if(j%2){
                    p++;
                }
                else i++;
            }
        }
    }

    if(pos[2*n-1]=='1'){
        if(pos[0]=='0')
        p++;
        else i++;
    } 

    cout << i << " " << p << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t; cin >> t;
    while(t--){
        solve(); 
    }
}

