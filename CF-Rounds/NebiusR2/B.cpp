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
const ll mod = 676767677;

void solve(){
    ll x, y; 
    cin >> x >> y;

    ll d=abs(x-y);
    ll ans =1;

    if(d!=0){
        ans =0;
        for(ll i =1; i *i<=d;i++){
            if(d%i==0){
                ans+=(i*i==d ?1:2);
            }
        }
    }

    cout << (ans%mod) << "\n";

    if(x >= y){
        f(i,0,y) cout <<-1<< " ";
        f(i,0,x) cout <<1<< " ";
    } else {
        f(i,0,x) cout <<1<< " ";
        f(i,0,y) cout <<-1<< " ";
    }
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    ll t; 
    cin >> t;
    while(t--) solve();
}