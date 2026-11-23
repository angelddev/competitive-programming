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

void solve(){
    ll n; cin >> n;
    vll heads(n);
    vll torzos(n);
    vll legs(n);

    f(i,0,n){
        cin >> heads[i];
    }
    f(i,0,n){
        cin >> torzos[i];
    }
    f(i,0,n){
        cin >> legs[i];
    }

    ll posUp2=0;
    f(i,0,n){
        ll temp=1;
        f(j,0,n){
            if(heads[j]>=torzos[(j+i)%n]){
                temp=0;
            }
        }
        if(temp==1) posUp2++;
    }
    
    ll posUp3=0;
    f(i,0,n){
        ll temp=1;
        f(j,0,n){
            if(torzos[j]>=legs[(j+i)%n]){
                temp=0;
            }
        }
        if(temp==1) posUp3++;
    }

    cout << posUp3*posUp2*n << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    ll t; cin >> t;
    while(t--)
    solve();
}