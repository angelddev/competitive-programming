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
ll pfx[100007];

void calc(){


    cf(i, 1, 100005){

        ll j = i;
        pfx[i]+=pfx[i-1];

        while(j>0){
            pfx[i]+=j%10;
            j/=10;
        }

    }

}

void solve(){

    ll l, r;
    cin >> l >> r;

    if(l == 0) cout << pfx[r] << "\n";
    else 
    cout << pfx[r]-pfx[l-1] << "\n";
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; cin >> t;
    calc();
    while(t--){
        solve(); 
    }
}

