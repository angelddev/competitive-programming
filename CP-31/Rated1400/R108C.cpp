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
    vll positions(n+1);
    f(i,0,n){
        cin >> positions[i];
    }

    vvl unis(n+1);
    ll x;
    f(i,0,n){
        cin >> x;
        unis[positions[i]].pb(x);
    }
    f(i,0,n+1){
        if(!unis[i].empty())
            sort(all(unis[i]));
    }

    vvl unispfx = unis;
    f(i,0,n+1){
        if(!unis[i].empty()){
            f(j,1,unis[i].size()){
                unispfx[i][j]+=unispfx[i][j-1];
            }
        }
    }

    vll ans(n);

    f(i,0,n+1){
        if(!unis[i].empty()){
            f(j,0,unis[i].size()){
                if(unis[i].size()-((unis[i].size())/(j+1))*(j+1)==0){
                    ans[j]+=unispfx[i][unis[i].size()-1];
                } else 
                ans[j]+=unispfx[i][unis[i].size()-1]-unispfx[i][unis[i].size()-((unis[i].size())/(j+1))*(j+1)-1];
            }
        }
    }

    f(i,0,n){
        cout << ans[i] << " ";
    }
    cout << "\n";

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    ll t; cin >> t;
    while(t--)
        solve();
}