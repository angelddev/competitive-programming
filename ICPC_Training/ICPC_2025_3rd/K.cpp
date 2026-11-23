#include <bits/stdc++.h>
using namespace std;
#define all(a) begin(a), end(a)
#define ll long long
#define pll pair<ll>
#define vll vector<ll>
#define vvl vector<vll>
#define f(i,s,e) for(ll i=s; i<e; i++)
#define pb push_back()
#define F first
#define S second
#define cf(i,s,e) for(ll i=s; i<=e; i++)

void solve(){

    ll a, b, c, d; cin >> a >> b >> c >> d;
    if(b>c&&d>a){
        if(a<=c){
            if(d<=b){
                cout << d-c << "\n";
            }
            else cout << b-c << "\n";
            return;
        } else if(d<=b) cout << d-a << "\n";
        else cout << b-a << "\n";
    } else cout << 0 << "\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll t; cin >> t; while(t--)
    solve();
}