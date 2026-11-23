#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n';

int main(){
    ll n; cin >> n;
    vector<ll> a(n);

    for(ll i=0; i<n; i++){
        cin >> a[i];
    }

    ll total=1;
    multiset<ll> limits;
    limits.insert(a[0]);

    for(ll i=1; i<n; i++){
        auto it=limits.upper_bound(a[i]);
        if(it==limits.end()){
            total++;
            limits.insert(a[i]);
        } else{
            limits.erase(it);
            limits.insert(a[i]);
        }
    }
    cout << total << endl;
}