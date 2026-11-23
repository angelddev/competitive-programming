#include<bits/stdc++.h>
 
#define ll long long 
#define all(a) begin(a), end(a)
#define pll pair<ll, ll> 
#define vll vector<ll>
#define vvl vector<vll>
#define vpl vector<pll> 
#define f(i, s, e) for(ll i=s; i<e; i++)
#define cf(i, s, e) for(ll i=s; i<=e; i++)
#define rf(i, s, e) for(ll i=s; i<e; i--)
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
    
    ll x,y; cin >> x >> y;

    ll ideal1, ideal2;


    if(3*x==2*y){
        cout << "Bob" << "\n";
        return;
    }


    ll diff=y-x;
    if(diff<=0||x<=2){
        cout << "Alice" << "\n";
        return;
    }

    if(x%2){
        ideal1=x-1;
        ideal2=(ideal1/2)*3;

        ll idealdiff=ideal2-ideal1;

        if(diff>idealdiff){
            cout << "Alice" << "\n";
            return;
        }
    }
    else {
        ideal1=x;
        ideal2=(ideal1/2)*3;

        ll idealdiff=ideal2-ideal1;

        if(diff>idealdiff){
            cout << "Alice" << "\n";
            return;
        }
    }
    cout << "Bob" << "\n";
    
}





int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    ll t; cin >> t;
    while(t--)
    solve();
}