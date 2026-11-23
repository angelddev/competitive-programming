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
 
ll recc(vll Joseph){
    if(Joseph.size()==1){
        cout << Joseph[0] << "\n";
        return 1;
    }
    vll temp;

    ll sz=Joseph.size();
    if(sz%2==1)
    temp.pb(Joseph[sz-1]);

    f(i,0,sz){
        if(i%2==0){
            temp.pb(Joseph[i]);
        } else cout << Joseph[i] << " ";
    }

    if(sz%2==1)
    temp.pop_back();
    recc(temp);
    if(Joseph.size()==1){
        cout << Joseph[0] << "\n";
        return 1;
    }else return 0;
}

void solve(){
    ll n; cin >> n;
    vll Joseph(n);
    f(i,0,n) Joseph[i]=i+1;
    recc(Joseph);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    //ll t; cin >> t;
    //while(t--)
        solve();
}