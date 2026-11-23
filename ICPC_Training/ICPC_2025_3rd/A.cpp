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

    ll n; cin >> n;

    ll x, sum=0;
    f(i,0,n){
        cin >> x; sum+=x;
    }

    ll original=n;
    while(sum%n!=0){
        n--;
    }
    cout << original-n << "\n";
}

int main(){
    //ll t; cin >> t; while(t--)
    solve();
}