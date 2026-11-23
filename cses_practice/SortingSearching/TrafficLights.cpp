#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

void solve(){

    ll n, m; cin >> n >> m;
    set<ll> s;
    multiset<ll> diffs; diffs.insert(n);
    s.insert(0), s.insert(n);

    ll x;
    for(ll i=0; i<m; i++){
        cin >> x;
        ll l= *prev(s.lower_bound(x));
        ll r= *s.upper_bound(x);
        diffs.insert(r-x);
        diffs.insert(x-l);
        diffs.erase(diffs.find(r-l));
        s.insert(x);
        cout << *prev(diffs.end()) << " ";
    }
    cout << endl;
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
    
}

