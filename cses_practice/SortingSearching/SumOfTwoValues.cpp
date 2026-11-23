#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef long long ll;

void solve(){

    ll n, x; cin >> n >> x;

    vector<pair<ll, ll>> values(n);
    for(ll i=0; i<n; i++){
        cin >> values[i].first;
        values[i].second=i+1;
    }

    sort(values.begin(), values.end());

    for(ll i=0; i<n; i++){
        if(values[i].first>=x){
            break;
        }
        ll goal=x-values[i].first;
        auto it = (upper_bound(values.begin(), values.end(), make_pair(goal, (ll)10e6)));
        if(it==values.begin()){
            continue;
        }
        pair<ll, ll> temp = *prev(it);
        if(temp.first==goal&&temp.second!=values[i].second){
            cout << values[i].second << " " << temp.second << endl;
            return;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}
