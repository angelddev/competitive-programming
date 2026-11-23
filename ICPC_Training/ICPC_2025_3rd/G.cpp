#include <bits/stdc++.h>
using namespace std;

#define all(a) begin(a), end(a)
#define ll long long
#define pll pair<ll>
#define vll vector<ll>
#define vvl vector<vll>
#define f(i,s,e) for(ll i=s; i<e; i++)
#define pb push_back
#define F first
#define S second
#define cf(i,s,e) for(ll i=s; i<=e; i++)
#define INF 1e18

void solve() {
    long double n, m, k;
    cin >> n >> m >> k;


    ll l = 0, r = 1e18;

    while(l < r){
        ll mid=(l+r)/2;
        if(n*pow((k-1)/k, mid) <= m)
            r = mid;
        else
            l = mid+1;
    }
    cout << l << "\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll t; cin >> t; while(t--)
    solve();
}