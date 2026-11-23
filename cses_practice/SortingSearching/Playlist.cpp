#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

void solve(){

    ll n; cin >> n;
    vector<pair<ll,ll>> a(n);

    for(ll i=0; i<n; i++){
        cin >> a[i].first;
        a[i].second=i;
    }

    set<pair<ll, ll>> check;
    ll mx=1, l=0, r;
    for(r=0; r<n; r++){

        pair<ll, ll> temp = a[r];
        temp.second=0;
        auto it= check.lower_bound(temp);

        if(it==check.end()){
        }
        else if(it->first==a[r].first){
            l = max(l, it->second + 1);
            check.erase(it);
        }
        
        check.insert(a[r]);
         
        mx=max(mx, r-l+1);
    }

    cout << mx << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}