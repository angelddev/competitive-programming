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
    char p, q; cin >> p >> q;

    vll pfx(10, 0);


    pfx[0] = 0; pfx[1] = 3; pfx[2] = 4; pfx[3] = 8; pfx[4] = 9; pfx[5] = 14; pfx[6] = 23;
    ll p1 = p-'A'; ll p2 = q-'A';
    cout << pfx[max(p1, p2)]-pfx[min(p1, p2)] << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; //cin >> t;
    while(t--){
        solve(); 
    }
}

