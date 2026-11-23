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
 
    ll n, b; cin >> n >> b;

    vll original(n);
    f(i,0,n){
        cin >> original[i];
    }

    vpl compact;
    compact.pb({original[0], 1});
    ll last=0;
    f(i,1,n){
        if(original[i]==original[i-1]){
            compact[last].S++;
        } else{
            last++;
            compact.pb({original[i],1});
        }
    }

    vll pivot;
    ll sz=compact.size();

    if(sz>2){
        f(i,0,sz){
            ll l=(i-1+sz)%sz; ll r=(i+1)%sz;
            if(compact[i]<compact[l]&&compact[i]<compact[r]){
                pivot.pb(i);
            }
        }
    }

    vll answer;
    ll szp = pivot.size();
    
    f(i,0,sz){
        
    }


}
 
int main(){
    ll t=1; 
    while(t--){
        solve(); 
    }
}