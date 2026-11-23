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
 

    ll tot, c2, a1, a2;


    cin >> tot >> c2 >> a1 >> a2;

    if(c2>tot){
        cout << max(0ll, tot-a1) << "\n";
        return;
    }

    if(a2*c2>tot){
        tot-=((tot/c2)*c2);
        cout << max(0ll, tot-a1) << "\n";
        return;
    }

    tot-=c2*a2;
    ll ans = 0;
    if(a1>=tot){
        tot = 0;
    } else {
        tot-=a1;
        ans+=((tot+(c2-1))/c2);
    }
    ans+=((tot+(c2-1))%c2);
    
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

