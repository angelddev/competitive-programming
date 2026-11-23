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

    ll n, copy, cont=0;
    cin >> n; 
    copy=n;
    if(copy<10){
        cout << copy+1 << "\n";
        return;
    } else {
        while(copy>=10){
        copy/=10;
        cont++;
        }
    }
    cont*=10;  
    ll ans=cont;
    vll digits;
    ll temp = n;

    if (temp == 0) digits.pb(0);

    while (temp > 0) {
        digits.pb(temp % 10);
        temp /= 10;
    }

    reverse(all(digits));

    ll looking=digits[0];
    ll band=0; cont=1;
    f(i,1,digits.size()){
        if(digits[i]==looking) {cont++; continue;}
        if(digits[i]>looking) band=1;
        break;
    }
    if(cont==digits.size()||band==1){
        ans+=copy;
    } else ans+=copy-1;

    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    //ll t; cin >> t;
    //while(t--)
        solve();
}