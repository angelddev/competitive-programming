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
    
    ll n, m; cin >> n >> m;

    vll remainders(100007);
    ll x;
    f(i,0,n){
        cin >> x; 
        remainders[x%m]++;
    }


    ll groups=0;
    f(i,0,100007){
        if(remainders[i]>0){
            if(i==0){
                groups++;
                continue;
            }
            ll needed=m-i;
            if(remainders[needed]>0){
                if(abs(remainders[i]-remainders[needed])>1){
                    if(remainders[i]>remainders[needed]){
                        groups++;
                        remainders[i]=remainders[i]-(remainders[needed]+1);
                        groups+=remainders[i];
                        remainders[needed]=0;
                        remainders[i]=0;
                    } else {
                        groups++;
                        remainders[needed]=remainders[needed]-(remainders[i]+1);
                        groups+=remainders[needed];
                        remainders[i]=0;
                        remainders[needed]=0;
                    }
                } else {
                    groups++;
                    remainders[needed]=0;
                    remainders[i]=0;
                }
            }
            else {
                groups+=remainders[i];
                remainders[i]=0;
            }
        }
    }

    cout << groups << "\n";
}

int main(){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t; cin >> t;
    while(t--) solve();
}