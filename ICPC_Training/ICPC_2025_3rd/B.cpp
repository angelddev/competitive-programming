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
    ll sum=0;
    vll nums(n);
    f(i,0,n){
        cin >> nums[i];
    }

    f(i,0,n){
        sum+=nums[i]*(i+1)*(n-i);
    }
    cout << sum << "\n";
    
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    //ll t; cin >> t; while(t--)
    solve();
}