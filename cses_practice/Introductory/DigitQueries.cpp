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


void solve(){

    ll n; cin >> n;

    ll digits=0, copy=n;
    while(copy>0){
        copy/=10;
        digits++;
    }

    vll blocks;
    f(i,0,17){
        blocks.pb((9*pow(10, i))*(i+1));
    }

    ll copy2=n, i=0; 
    while(blocks[i]<copy2){
        copy2-=blocks[i];
        i++;
    }
    ll d=i+1;
    ll start = 1;
    f(j,1,d) start *= 10;
    ll number = start + (copy2 - 1) / d;
    ll index = (copy2 - 1) % d;
    string s = to_string(number);
    cout << s[index] << "\n";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t; cin >> t;
    while(t--){
        solve(); 
    }
}