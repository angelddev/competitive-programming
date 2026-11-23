#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n';
using namespace std;

void solve(){
    ll n; cin >> n;

    vector<pair<ll, ll>> movies(n);
    for(ll i=0; i< n; i++){
        cin >> movies[i].second >> movies[i].first;
    }
    
    sort(movies.begin(), movies.end());
    ll mx=1, mnhour=movies[0].first;
    for(ll i=1; i<n; i++){
        if(movies[i].second>=mnhour){
            mx++;
            mnhour=movies[i].first;
        }
    }
    cout << mx << endl;

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}