#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n';

void solve(){

    ll n; cin >> n;
    vector<ll> a(n);

    for(ll &i:a)
        cin >> i;
    sort(a.begin(), a.end());
    ll sum=0;
    for(ll i=0; i<n; i++)
        if(a[i]!=(a[n/2]))
            sum+=abs(a[n/2]-a[i]);
    
    cout << sum << endl;

    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}
