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
const ll mod = 998244353;

void solve(){

    ll n; cin >> n;
    vector<pair<pll, ll>> ranges(n);

    ll x, y, id;
    f(i,0,n){
        cin >> x >> y;
        id=i;
        ranges[i].F.F=x;
        ranges[i].F.S=-1*y;
        ranges[i].S=id;
    }

    sort(all(ranges));

    vll inside(n, 0), outside(n, 0);
    ll mx=0;
    f(i,0,n){
        if(mx>=abs(ranges[i].F.S)){
            inside[ranges[i].S]=1;
        } else mx=ranges[i].F.S*-1;
    }

    ll mn=INF;
    for(ll i=n-1; i>=0; i--){
        if(mn<=abs(ranges[i].F.S)){
            outside[ranges[i].S]=1;
        } else mn=ranges[i].F.S*-1;
    }

    f(i,0,n){
        cout << outside[i] << " ";
    }
    cout << "\n";
    f(i,0,n){
        cout << inside[i] << " ";
    }
    cout << " \n";
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    //ll t; cin >> t;
    //while(t--)
        solve();
}