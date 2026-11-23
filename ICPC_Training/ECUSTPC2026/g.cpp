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

ll n, a, b; 
ll ansn, ansm; 

void solve(){
    cin>>n; 
    vll win;
    ll mwin=INF, mdif=0;
    vpl scores;
    f(i, 0, n){
        cin>>a>>b; 
        scores.pb({a, b}); 
        win.pb(max(a, b));
        mwin=min(mwin, max(a, b)); 
    }
    for(auto [a, b]: scores){
        if(max(a, b)==mwin) continue; 
        mdif=max(mdif, max(a, b)-min(a, b)); 
    }
    ll g=0;
    for(auto u: win){
        if(u==mwin) continue;   
        g=__gcd(g, u-mwin); 
    }
    //cout<<g<<" "<<mdif<<" "; 
    if(g>=mdif-1){
        cout<<"YES\n";
        return;
    }
    sort(all(win)); 
    g=0; 
    f(i, 1, n){
        g=__gcd(g, win[i]-win[i-1]); 
    }
    if(g>=mdif-1){
        cout<<"YES\n";
        return;
    }
    cout<<"NO\n"; 

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t; cin >> t;
    while(t--){
        solve(); 
    }
}