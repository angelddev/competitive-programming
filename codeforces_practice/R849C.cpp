#include<bits/stdc++.h>
 
#define ll long long 
#define all(a) begin(a), end(a)
#define pll pair<ll, ll> 
#define vll vector<ll>
#define vvl vector<vll>
#define vpl vector<pll> 
#define f(i, s, e) for(ll i=s; i<e; i++)
#define cf(i, s, e) for(ll i=s; i<=e; i++)
#define rf(i, s, e) for(ll i=s; i>=e; i--) 
#define MOD(x) ((((x)%mod) + mod)%mod)
#define F first
#define S second
#define pb push_back 
using namespace std; 
typedef long double ld;
 
const ll INF = 1e18; 
const ll mod = 1e9 + 7;
 
ll t, n, m, k, a, b, tot; 
 
void solve(){
   
    ll n; cin >> n;
    string s; cin >> s;

    vll pfx(n);
    pfx[0]=1;
    vll sfx(n);
    sfx[n-1]=1;

    set<char> app;
    app.insert(s[0]);
    f(i,1,n){
        if(app.find(s[i])==app.end()){
            pfx[i]=pfx[i-1]+1;
            app.insert(s[i]);
        } else pfx[i]=pfx[i-1];
    }

    set<char> app2;
    app2.insert(s[n-1]);
    for(ll i=n-2; i>=0; i--){
        if(app2.find(s[i])==app2.end()){
            sfx[i]=sfx[i+1]+1;
            app2.insert(s[i]);
        } else sfx[i]=sfx[i+1];
    }

    ll mx=1;
    for(int i=0, j=1; i<n-1; i++, j++){
        mx=max(mx, pfx[i]+sfx[j]);
    }

    cout << mx << "\n";
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    ll t; cin >> t;
    while(t--)
        solve();
}