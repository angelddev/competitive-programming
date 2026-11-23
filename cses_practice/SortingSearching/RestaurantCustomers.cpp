#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

void solve(){
    
    ll n; cin >> n;
    vector<pair<int, int>> times(n);
    for(ll i=0; i<n; i++){
        cin >> times[i].first >> times[i].second;
    }

    sort(times.begin(), times.end());

    ll mx=1, curr=0;
    multiset<ll> que;
    for(ll i=0; i<n; i++){
        que.insert(times[i].second);
        while(times[i].first>*que.begin())
            que.erase(que.begin());
        curr=que.size();
        mx=max(curr, mx);
    }

    cout << mx << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}