#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll= long long;

void solve(){
    ll n; cin >> n;
    vector<pair<ll, ll>> a(n);
    for(ll i=0; i<n; i++){
        cin >> a[i].first;
        a[i].second=i+1;
    }
    sort(a.begin(), a.end());

    ll sum=0;
    for(int i=0; i<n-1; i++){
        if(a[i].second>a[i+1].second){
            sum++;
        }
    }
    cout << sum+1 << endl;
    
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}