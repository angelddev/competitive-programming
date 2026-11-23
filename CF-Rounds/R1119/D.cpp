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

    vll arr(n);
    ll cont = 0;
    vpl an(n);
    
    f(i,0,n){
        cin >> arr[i];
        if(arr[i]==0){
            cont++;
        }
        an[i] = {arr[i], i}; 
    }

    if(cont == 1){
        cout << "NO\n";
        return;
    } 

    sort(all(an));

    vector<char> st(n);
    ll mA = 0, mB = 0, mC = 0;
    
    for(pll el : an){
        ll v = el.F;
        ll idx = el.S;
        
        if (v >= mA + 1) {
            st[idx]='A';
        } else if (v>=mB+1) {
            st[idx]='B';
        } else if (v>=mC+1) {
            st[idx]='C';
        } else {
            ll mm = min({mA, mB, mC});
            if (mA==mB&&mB==mC) {
                st[idx]='A';
                if (v==mA) mA++;
            } else if (mm==mA) {
                st[idx]='A';
                if (v==mA) mA++;
            } else if (mm==mB) {
                st[idx]='B';
                if (v==mB) mB++;
            } else {
                st[idx]='C';
                if (v==mC) mC++;
            }
        }
    }
 
    cout << "YES\n";
    f(i,0,n){
        cout << st[i];
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

