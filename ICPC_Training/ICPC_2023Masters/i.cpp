#include <bits/stdc++.h>
using namespace std;
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

ll t, n, m, k, a, b; 

void solve(){
    cin >> n >> k;
    if(n%k==0){
        cout << k << "\n";
    } else
    cout << n%k << "\n";
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    t=1; 
    while(t--){
        solve();
    }
}