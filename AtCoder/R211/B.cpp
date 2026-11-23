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

    ll x, y, z;
    cin >> x >> y >> z;

     vll a, b, c;

    if(x==y){
        f(i,0,x){
            a.pb(0);
        }
        f(i,0,z){
            b.pb(0);
            c.pb(0);
        } 
    }
   else {
    f(i,0,x){
        a.pb(0);
        b.pb(0);
    }
    
    f(i,0,y){
        a.pb(1);
        c.pb(1);
    }
    f(i,0,z){
        b.pb(0);
        c.pb(0);
    } 
}
   
    cout << a.size() << " ";
    for(auto i : a){
        cout << i << " ";
    } cout << "\n";
    cout << b.size() << " ";
    for(auto i : b){
        cout << i << " ";
    } cout << "\n";
    cout << c.size() << " ";
    for(auto i : c){
        cout << i << " ";
    } cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t=1;
    while(t--){
        solve(); 
    }
}