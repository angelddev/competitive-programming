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

    ll n, bonitos, p; cin >> n >> bonitos >> p;

    ll x;
    f(i,0,bonitos){
        cin >> x;
    }
    n--;

    ll feosRoot = p-bonitos;
    ll feosHijos = n-bonitos-feosRoot;

    ll ans = 0;
    ll ansRoot = bonitos+2*feosRoot+2*feosHijos;    
    ll ansfR = feosRoot*(2+3*bonitos+4*feosHijos+4*(feosRoot-1));
    ll ansfH = feosHijos*(1+2+3*(bonitos-1)+4*feosRoot+2*(feosHijos-1));
    ll ansBonitos = (bonitos-1)*(2*(bonitos-1)+1+3*feosRoot+3*feosHijos);
    ll extra = 2*(bonitos-1)+1+3*feosRoot+feosHijos;

    ans+=ansRoot+ansfR+ansfH+ansBonitos+extra;

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

